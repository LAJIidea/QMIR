#ifndef QMIR_DEMO_PARSER_H
#define QMIR_DEMO_PARSER_H

#include "AST.h"
//#include "Lexer.h"

#include <llvm/ADT/Optional.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/ADT/StringExtras.h>
#include <llvm/Support/raw_os_ostream.h>

#include <map>
#include <utility>
#include <vector>

namespace qmir
{
	class Parser
	{
	public:
		Parser(Lexer& lexer) : lexer(lexer) {}

		std::unique_ptr<ModuleAST> parseModule()
		{
			lexer.getNextToken();
			std::vector<CircuitAST> circuits;

			while (auto c = parseCircuit())
			{
				circuits.push_back(std::move(*c));
				if (lexer.getCurToken() == tok_eof)
				{
					break;
				}
			}

			if (lexer.getCurToken() != tok_eof)
			{
				return parseError<ModuleAST>("nothing", "at end of module");
			}

			return std::make_unique<ModuleAST>(std::move(circuits));
		}

	private:
		Lexer& lexer;

		// number expr ::= number
		std::unique_ptr<ExprAST> parseNumberExpr()
		{
			auto loc = lexer.getLastLocation();
			auto result = std::make_unique<NumberExprAST>(std::move(loc), lexer.getValue());
			lexer.consume(tok_number);
			return std::move(result);
		}

		std::unique_ptr<ExprAST> parseQubit()
		{
			auto loc = lexer.getLastLocation();
			if (lexer.getCurToken() != tok_qubit)
			{
				return parseError<ExprAST>("qubit", "in Qubit Alloc");
			}
			lexer.consume(tok_qubit);
			if (lexer.getCurToken() != tok_identifier)
			{
				return parseError<ExprAST>("qubit name", "in Qubit Alloc");
			}
			std::string qubitName(lexer.getId());
			lexer.consume(tok_identifier);

			if (lexer.getCurToken() != '(')
			{
				return parseError<ExprAST>("(", "in Qubit Alloc");
			}
			lexer.consume(Token('('));

			if (lexer.getCurToken() != tok_number)
				return parseError<ExprAST>("size number", "in Qubit Alloc");
			double size = lexer.getValue();
			lexer.consume(tok_number);


			lexer.consume(Token(')')); // eat ')'

			auto q = std::make_unique<QubitExprAST>(std::move(loc), qubitName, size);
			return q;
		}

		std::unique_ptr<ExprAST> parseCbit()
		{
			auto loc = lexer.getLastLocation();
			if (lexer.getCurToken() != tok_cbit)
			{
				return parseError<ExprAST>("cbit", "in Cbit Alloc");
			}
			lexer.consume(tok_cbit);
			if (lexer.getCurToken() != tok_identifier)
			{
				return parseError<ExprAST>("cbit name", "in Cbit Alloc");
			}
			std::string cbitName(lexer.getId());
			lexer.consume(tok_identifier);

			if (lexer.getCurToken() != '(')
			{
				return parseError<ExprAST>("(", "in Cbit Alloc");
			}
			lexer.consume(Token('('));

			if (lexer.getCurToken() != tok_number)
				return parseError<ExprAST>("size number", "in Cbit Alloc");
			double size = lexer.getValue();
			lexer.consume(tok_number);


			lexer.consume(Token(')')); // eat ')'

			auto c = std::make_unique<CbitExprAST>(std::move(loc), cbitName, size);
			return std::move(c);
		}

		std::unique_ptr<ExprAST> parseGate()
		{
			auto loc = lexer.getLastLocation();
			if (lexer.getCurToken() != tok_gate)
			{
				return parseError<ExprAST>("quantum gate", "quantum circuit");
			}
			auto gateName = lexer.getCurGate();
			lexer.consume(tok_gate);

			if (lexer.getCurToken() != '(')
			{
				return parseError<ExprAST>("(", "in quantum gate");
			}
			lexer.consume(Token('('));

			std::vector<std::unique_ptr<ExprAST>> args;
			if (lexer.getCurToken() != ')')
			{
				do
				{
					auto v = parseExpression();
					if (!v)
					{
						return parseError<ExprAST>("qubit", "in quantum gate");
					}
					args.push_back(std::move(v));
					if (lexer.getCurToken() != ',')
					{
						break;
					}
					lexer.consume(Token(','));
				} while (true);
			}

			if (lexer.getCurToken() != ')')
			{
				return parseError<ExprAST>(")", "in quantum gate close with paren");
			}

			lexer.consume(Token(')'));
			return std::make_unique<GateExprAST>(std::move(loc), gateName, std::move(args));
		}

		std::unique_ptr<PrototypeAST> parsePrototype()
		{
			auto loc = lexer.getLastLocation();
			if (lexer.getCurToken() != tok_circuit)
			{
				return parseError<PrototypeAST>("circuit", "in prototype");
			}
			lexer.consume(tok_circuit);

			if (lexer.getCurToken() != tok_identifier)
			{
				return parseError<PrototypeAST>("circuit name", "in circuit");
			}
			std::string name(lexer.getId());
			lexer.consume(tok_identifier);
			if (lexer.getCurToken() != '(')
			{
				return parseError<PrototypeAST>("(", "in circuit");
			}
			lexer.consume(Token('('));

			std::vector<std::unique_ptr<IdentifierExprAST>> args;
			if (lexer.getCurToken() != ')')
			{
				do
				{
					std::string name(lexer.getId());
					auto loc = lexer.getLastLocation();
					lexer.consume(tok_identifier);
					auto variable = std::make_unique<IdentifierExprAST>(std::move(loc), name);
					args.push_back(std::move(variable));
					if (lexer.getCurToken() != ',')
						break;
					lexer.consume(Token(','));
					if (lexer.getCurToken() != tok_identifier)
						return parseError<PrototypeAST>("variable", "in circuit parameter list");
				} while (true);
			}
			if (lexer.getCurToken() != ')')
			{
				return parseError<PrototypeAST>(")", "to end circuit prototype");
			}
			lexer.consume(Token(')'));
			return std::make_unique<PrototypeAST>(std::move(loc), name, std::move(args));
		}

		std::unique_ptr<CircuitAST> parseCircuit()
		{
			auto loc = lexer.getLastLocation();

			auto proto = parsePrototype();
			if (!proto)
			{
				return nullptr;
			}

			if (lexer.getCurToken() != '{')
			{
				return parseError<CircuitAST>("{", "in circuit");
			}
			lexer.consume(Token('{'));

			auto exprList = std::make_unique<ExprASTList>();

			while (lexer.getCurToken() != '}' && lexer.getCurToken() != tok_eof)
			{
				auto expr = parseExpression();
				if (!expr)
				{
					return nullptr;
				}
				exprList->push_back(std::move(expr));
			}
			lexer.consume(Token('}'));
			return std::make_unique<CircuitAST>(std::move(loc), std::move(proto), std::move(exprList));
		}

		std::unique_ptr<ExprAST> parseIdentifierExpr()
		{
			auto loc = lexer.getLastLocation();
			std::string name(lexer.getId());
			lexer.consume(tok_identifier);
			if (lexer.getCurToken() != '[')
				return std::make_unique<IdentifierExprAST>(std::move(loc), name);
			auto v = parseBracketExpr();
			if (!v)
			{
				return parseError<ExprAST>("num value", "in qubit list");
			}
			//lexer.getNextToken(); // move to next
//            if (llvm::any_of(values, [](std::unique_ptr<ExprAST> &expr) {
//                return llvm::isa<LiteralExprAST>(expr.get());
//            }
			return std::make_unique<ListExprAST>(std::move(loc), name, std::move(v));
		}

		// brackets expr  ::= '[' expression ']'
		std::unique_ptr<ExprAST> parseBracketExpr()
		{
			if (lexer.getCurToken() != '[')
			{
				return parseError<ExprAST>("[", "in list");
			}
			lexer.getNextToken();
			auto v = parseExpression();
			if (!v)
			{
				return nullptr;
			}

			if (lexer.getCurToken() != ']')
			{
				return parseError<ExprAST>("]", "to close expression with bracket");
			}
			lexer.consume(Token(']'));
			return v;
		}

		// primary
		//		::= identifier expr
		//		::= number expr
		//		::= brackets expr
		std::unique_ptr<ExprAST> parseExpression()
		{
			switch (lexer.getCurToken())
			{
			default:
				llvm::errs() << "unknown token '" << lexer.getCurToken() << "' when expecting an expression\n";
				return nullptr;
			case tok_identifier:
				return parseIdentifierExpr();
			case tok_number:
				return parseNumberExpr();
			case tok_qubit:
				return parseQubit();
			case tok_cbit:
				return parseCbit();
			case tok_gate:
				return parseGate();
			}
		}

		template <typename R, typename T, typename U = const char*>
		std::unique_ptr<R> parseError(T&& expected, U&& context = "")
		{
			auto curToken = lexer.getCurToken();
			llvm::errs() << "Parse error (" << lexer.getLastLocation().line << ", " << lexer.getLastLocation().col << "): expected '" << expected << "' " << context << " but has Token " << curToken;
			if (isprint(curToken))
			{
				llvm::errs() << " '" << (char)curToken << "'";
			}
			llvm::errs() << "\n";
			return nullptr;
		}

	};
}


#endif // !QMIR_DEMO_PARSER_H


