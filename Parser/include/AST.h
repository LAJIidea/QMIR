#ifndef QMIR_DEMO_AST_H_
#define QMIR_DEMO_AST_H_

#include "Lexer.h"

#include <llvm/ADT/ArrayRef.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Casting.h>
#include <vector>
#include <map>

namespace qmir
{
	struct VarType
	{
		std::vector<int64_t> shape;
	};

	class ExprAST
	{
	public:
		enum ExprASTKind
		{
			Expr_Qubit,
			Expr_Cbit,
			Expr_Identifier,
			Expr_Num,
			Expr_List,
			Expr_Gate,
		};

		ExprAST(ExprASTKind kind, Location location)
			: kind(kind), location(location) {}

		//virtual ~ExprAST() = default;

		ExprASTKind getKind() const { return kind; }

		const Location& loc() { return location; }

	private:
		ExprASTKind kind;
		Location location;

	};

	using ExprASTList = std::vector<std::unique_ptr<ExprAST>>;

	class NumberExprAST : public ExprAST
	{
		double Val;
	public:
		NumberExprAST(Location loc, double val)
			: ExprAST(Expr_Num, loc), Val(val) {}

		double getValue() { return Val; }

		static bool classof(const ExprAST* c)
		{
			return c->getKind() == Expr_Num;
		}
	};

	class ListExprAST : public ExprAST
	{
		std::string Name;
		std::unique_ptr<ExprAST> index;
	public:
		ListExprAST(Location loc, llvm::StringRef val, std::unique_ptr<ExprAST> index)
			: ExprAST(Expr_List, loc), Name(val), index(std::move(index)) {}

		std::string getValue() { return Name; }

		ExprAST* getIndex() { return index.get(); }

		static bool classof(const ExprAST* c)
		{
			return c->getKind() == Expr_List;
		}
	};

	class IdentifierExprAST : public ExprAST
	{
		std::string Val;
		std::unique_ptr<ExprAST> ex;
	public:
		IdentifierExprAST(Location loc, llvm::StringRef val)
			: ExprAST(Expr_Identifier, loc), Val(val) {}

		std::string getValue() { return Val; }

		static bool classof(const ExprAST* c)
		{
			return c->getKind() == Expr_Identifier;
		}
	};

	class QubitExprAST : public ExprAST
	{
		std::string name;
		double size;
	public:
		QubitExprAST(Location loc, llvm::StringRef name, double size)
			: ExprAST(Expr_Qubit, loc), name(name), size(size) {}

		std::string getName() { return name; }

		double getSize() { return size; }

		static bool classof(const ExprAST* c)
		{
			return c->getKind() == Expr_Qubit;
		}

	};

	class CbitExprAST : public ExprAST
	{
		std::string name;
		double size;
	public:
		CbitExprAST(Location loc, llvm::StringRef name, double size)
			: ExprAST(Expr_Cbit, loc), name(name), size(size) {}

		llvm::StringRef getName() { return name; }

		double getSize() { return size; }

		static bool classof(const ExprAST* c)
		{
			return c->getKind() == Expr_Cbit;
		}

	};

	class GateExprAST : public ExprAST
	{
		std::string callee;
		std::vector<std::unique_ptr<ExprAST>> args;
//		std::map<std::string, IdentifierExprAST> vars;
	public:
		GateExprAST(Location loc, const std::string& callee, std::vector<std::unique_ptr<ExprAST>> args)
			: ExprAST(Expr_Gate, loc), callee(callee), args(std::move(args)) {}

		llvm::StringRef getCallee()
		{
			return callee;
		}
		llvm::ArrayRef<std::unique_ptr<ExprAST>> getArgs() { return args; }

//		std::map<std::string, IdentifierExprAST> getVar() { return vars; }

		static bool classof(const ExprAST* c)
		{
			return c->getKind() == Expr_Gate;
		}
	};

	class PrototypeAST
	{
		Location location;
		std::string name;
		std::vector<std::unique_ptr<IdentifierExprAST>> args;
	public:
		PrototypeAST(Location location, const std::string& name,
			std::vector<std::unique_ptr<IdentifierExprAST>> args)
			: location(location), name(name), args(std::move(args)) {}

		const Location& loc() { return location; }
		llvm::StringRef getName() const { return name; }

		llvm::ArrayRef<std::unique_ptr<IdentifierExprAST>> getArgs() { return args; }
	};

	class CircuitAST
	{
		std::unique_ptr<PrototypeAST> proto;
		std::unique_ptr<ExprASTList> body;
		Location location;
	public:
		CircuitAST(Location loc, std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprASTList> body)
			: location(loc), proto(std::move(proto)), body(std::move(body)) {}
		PrototypeAST* getProto() { return proto.get(); }

		ExprASTList* getBody() { return body.get(); }

		const Location& loc() { return location; }
	};

	class ModuleAST
	{
		std::vector<CircuitAST> circuits;
	public:
		ModuleAST(std::vector<CircuitAST> circuits)
			: circuits(std::move(circuits)) {}

		auto begin() -> decltype(circuits.begin())
		{
			return circuits.begin();
		}

		auto end() -> decltype(circuits.end())
		{
			return circuits.end();
		}
		
		void dump(ModuleAST&);
	};

}

#endif
