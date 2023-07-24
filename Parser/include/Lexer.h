#ifndef QMIR_DEMO_LEXER_H_
#define QMIR_DEMO_LEXER_H_

#include "llvm/ADT/StringRef.h"
#include <memory>
#include <string>
#include<vector>
namespace qmir {


	struct Location
	{
		std::shared_ptr<std::string> file;
		int line;
		int col;
	};

	enum Token : int {
		tok_semicolon = ';',
		tok_parenthese_open = '(',
		tok_parenthese_close = ')',
		tok_bracket_open = '{',
		tok_bracket_close = '}',
		tok_sbracket_open = '[',
		tok_sbracket_close = ']',

		tok_eof = -1,
		tok_gate = -2,
		tok_qubit = -3,
		tok_cbit = -4,
		tok_number = -5,
		tok_identifier = -6,
		tok_circuit = -7,
	};

	class Lexer {
	public:
		Lexer(std::string filename)
			: lastLocation({ std::make_shared<std::string>(std::move(filename)), 0, 0 }) {}
		virtual ~Lexer() = default;

		Token getCurToken() { return curTok; }

		Token getNextToken() { return curTok = getTok(); }

		std::string getCurGate() { return curGate; }

		void consume(Token tok)
		{
			assert(tok == curTok && "consume Token mismatch expectation");
			getNextToken();
		}

		llvm::StringRef getId()
		{
			assert(curTok == tok_identifier);
			return identifierStr;
		}

		double getValue()
		{
			assert(curTok == tok_number);
			return numVal;
		}

		Location getLastLocation() { return lastLocation; }

		int getLine() { return curLineNum; }

		int getCol() { return curCol; }

	private:

		std::vector<std::string>gates{ "CNOT","H", "X", "Measure", "T", "S" };

		virtual llvm::StringRef readNextLine() = 0;

		int getNextChar() {
			if (curLineBuffer.empty())
			{
				return EOF;
			}
			++curCol;
			auto nextchar = curLineBuffer.front();
			curLineBuffer = curLineBuffer.drop_front();
			if (curLineBuffer.empty())
			{
				curLineBuffer = readNextLine();
			}
			if (nextchar == '\n')
			{
				++curLineNum;
				curCol = 0;
			}
			return nextchar;
		}

		Token getTok() {
			while (isspace(lastChar))
				lastChar = Token(getNextChar());

			lastLocation.line = curLineNum;
			lastLocation.col = curCol;

			if (isalpha(lastChar))
			{
				identifierStr = (char)lastChar;
				while (isalnum((lastChar = Token(getNextChar()))) || lastChar == '_')
					identifierStr += (char)lastChar;
				auto index = find(gates.begin(), gates.end(), identifierStr);
				if (index != gates.end())
				{
					std::string gateName = *index;
					curGate = gateName;
					return tok_gate;
				}
				if (identifierStr == "qubit")
					return tok_qubit;
				if (identifierStr == "cbit")
					return tok_cbit;
				if (identifierStr == "circuit")
					return tok_circuit;
				return tok_identifier;
			}

			if (isdigit(lastChar) || lastChar == '.')
			{
				std::string numStr;
				do
				{
					numStr += lastChar;
					lastChar = Token(getNextChar());
				} while (isdigit(lastChar) || lastChar == '.');

				numVal = strtod(numStr.c_str(), nullptr);
				return tok_number;
			}

			if (lastChar == '#')
			{
				do
				{
					lastChar = Token(getNextChar());
				} while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

				if (lastChar != EOF)
					return getTok();
			}

			if (lastChar == EOF)
				return tok_eof;

			Token thisChar = Token(lastChar);
			lastChar = Token(getNextChar());
			return thisChar;
		}

		Token curTok = tok_eof;

		std::string curGate = "unknown";

		Location lastLocation;

		std::string identifierStr;

		double numVal = 0;

		Token lastChar = Token(' ');

		int curLineNum = 0;

		int curCol = 0;

		llvm::StringRef curLineBuffer = "\n";
	};

	class LexerBuffer final : public Lexer {
	public:
		LexerBuffer(const char* begin, const char* end, std::string filename)
			: Lexer(std::move(filename)), current(begin), end(end) {}

	private:
		llvm::StringRef readNextLine() override {
			auto* begin = current;
			while (current <= end && *current && *current != '\n')
			{
				++current;
			}
			if (current <= end && *current)
				++current;
			llvm::StringRef result{ begin, static_cast<size_t>(current - begin) };
			return result;
		}

		const char* current, * end;
	};

}
#endif