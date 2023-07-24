#ifndef QMIR_MLIRGEN_H_
#define QMIR_MLIRGEN_H_

#include <memory>
#include "AST.h"
#include "Quantum/QuantumOps.h"
//#include <mlir/IR/Function.h>
#include <mlir/IR/Builders.h>
#include <llvm/ADT/ScopedHashTable.h>
#include <map>
#include <mlir/IR/BuiltinOps.h>

namespace qmir
{

	class MLIRGenImpl
	{
	public:
		MLIRGenImpl(mlir::MLIRContext& context);
		mlir::OwningModuleRef mlirGen(ModuleAST& moduleAST);
	private:
		std::map<std::pair<std::string, std::uint64_t>, mlir::Value> extracted_qubits;

		std::map<std::string, mlir::quantum::QallocOp> qubit_allocations;

		std::map<std::pair<std::string, std::uint64_t>, std::pair<int, mlir::quantum::InstOp>> beforeQubits;

		std::vector<std::pair<std::string, std::uint64_t>> markPos;

		mlir::ModuleOp theModule;

		mlir::OpBuilder builder;

		llvm::ScopedHashTable<llvm::StringRef, mlir::Value> symbolTable;

		mlir::Type qubit_type;
		mlir::Type array_type;
		mlir::Type cbit_type;

		mlir::Location loc(Location loc);
		mlir::LogicalResult declare(llvm::StringRef var, mlir::Value value);
		mlir::Value mlirGen(QubitExprAST& qubit);
		mlir::Value mlirGen(CbitExprAST& cbit);
		mlir::Value mlirGen(GateExprAST& gate);
		mlir::Value mlirGen(ListExprAST& list);
		mlir::Value mlirGen(NumberExprAST& number);
		mlir::FuncOp mlirGen(PrototypeAST& proto);
		mlir::LogicalResult mlirGen(ExprASTList& blockAST);
		mlir::FuncOp mlirGen(CircuitAST& circuitAST);
		mlir::Value mlirGen(ExprAST& expr);
		mlir::Type getType(llvm::ArrayRef<int64_t> shape);
		mlir::Type getType(const VarType& type);
	};
}

#endif // QMIR_MLIRGEN_H_