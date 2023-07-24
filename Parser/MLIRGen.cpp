#include "MLIRGen.h"
#include "AST.h"
#include "Quantum/QuantumOps.h"

#include <mlir/IR/Attributes.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/BuiltinTypes.h>
#include <mlir/IR/Verifier.h>
#include <mlir/Dialect/StandardOps/IR/Ops.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/Support/raw_os_ostream.h>
#include <numeric>
#include <iostream>

using namespace mlir::quantum;
using namespace qmir;

using llvm::ArrayRef;
using llvm::cast;
using llvm::dyn_cast;
using llvm::isa;
using llvm::makeArrayRef;
using llvm::ScopedHashTableScope;
using llvm::SmallVector;
using llvm::StringRef;
using llvm::Twine;

namespace qmir
{


	MLIRGenImpl::MLIRGenImpl(mlir::MLIRContext& context) : builder(&context)
	{
		mlir::Identifier dialect = mlir::Identifier::get("quantum", &context);
		StringRef qubit_type_name("Qubit"), array_type_name("Array"),
			cbit_type_name("Cbit");
		qubit_type = mlir::OpaqueType::get(&context, dialect, qubit_type_name);
		array_type = mlir::OpaqueType::get(&context, dialect, array_type_name);
		cbit_type = mlir::OpaqueType::get(&context, dialect, cbit_type_name);
	}

	mlir::OwningModuleRef MLIRGenImpl::mlirGen(ModuleAST& moduleAST)
	{
		theModule = mlir::ModuleOp::create(builder.getUnknownLoc());

		// Create a scope in the symbol table to hold variable declarations.
		for (CircuitAST& C : moduleAST)
		{
			auto circuit = mlirGen(C);
			if (!circuit)
			{
				return nullptr;
			}
			theModule.push_back(circuit);
		}

		//if (mlir::failed(mlir::verify(theModule)))
		//{
		//	theModule.emitError("module verification error");
		//	return nullptr;
		//}

		return theModule;
	}

	mlir::Location MLIRGenImpl::loc(Location loc)
	{
		return builder.getFileLineColLoc(builder.getIdentifier(*loc.file), loc.line, loc.col);
	}

	mlir::LogicalResult MLIRGenImpl::declare(StringRef var, mlir::Value value)
	{
		if (symbolTable.count(var))
		{
			return mlir::failure();
		}
		symbolTable.insert(var, value);
		return mlir::success();
	}

	mlir::Value MLIRGenImpl::mlirGen(QubitExprAST& qubit)
	{
		auto location = loc(qubit.loc());
		std::string name = qubit.getName();
		double size = qubit.getSize();
		std::int64_t size_t = size;
		auto integer_type = builder.getI64Type();
		auto integer_attr = mlir::IntegerAttr::get(integer_type, size_t);

		auto str_attr = builder.getStringAttr(name);

		auto allocation = builder.create<QallocOp>(location, array_type, integer_attr, str_attr);
		qubit_allocations.insert({ name, allocation });
		return allocation;
	}

	mlir::Value MLIRGenImpl::mlirGen(CbitExprAST& cbit)
	{
		return mlir::Value();
	}

	mlir::Value MLIRGenImpl::mlirGen(GateExprAST& gate)
	{
		markPos.clear();
		StringRef name = gate.getCallee();
		auto callee = builder.getStringAttr(name);
		auto location = loc(gate.loc());

		// Codegen the operands first
		SmallVector<mlir::Value, 4> operands;
		for (auto& expr : gate.getArgs())
		{
			auto arg = mlirGen(*expr);
			if (!arg)
			{
				return nullptr;
			}
			operands.push_back(arg);
		}


		if (name == "Measure")
		{
			if (operands.size() > 1)
				return nullptr;
			mlir::Value qubit = operands[0];
			return builder.create<MeasureOp>(location, cbit_type, qubit);
		}

		if (name == "CNOT")
		{
			auto op = builder.create<InstOp>(location, llvm::makeArrayRef(std::vector<mlir::Type>{qubit_type, qubit_type}),
				callee, operands, llvm::makeArrayRef(std::vector<mlir::Value>{}));
			for (int i = 0; i < markPos.size(); i++)
			{
				auto idx_pair = markPos[i];
				beforeQubits.insert({ idx_pair, std::make_pair(i, op) });
			}
			return mlir::Value();
		}

		auto op = builder.create<InstOp>(location, llvm::makeArrayRef(std::vector<mlir::Type>{qubit_type}),
			callee, operands, llvm::makeArrayRef(std::vector<mlir::Value>{}));
		for (int i = 0; i < markPos.size(); i++)
		{
			auto q = markPos[i];
			beforeQubits.insert({ q, std::make_pair(i, op) });
		}
		return mlir::Value();
	}

	mlir::Value MLIRGenImpl::mlirGen(ListExprAST& list)
	{
		auto location = loc(list.loc());
		std::string qubit_name = list.getValue();
		if (list.getIndex()->getKind() != ExprAST::Expr_Num)
		{
			return nullptr;
		}
		auto index = cast<NumberExprAST>(list.getIndex());
		std::uint64_t qidx = index->getValue();

		auto qubit_key = std::make_pair(qubit_name, qidx);

		mlir::Value qubit_value;
		if (beforeQubits.count(qubit_key))
		{
			auto qubit_pair = beforeQubits[qubit_key];
			int i = qubit_pair.first;
			auto val = qubit_pair.second;
			qubit_value = val.result()[i];
			markPos.push_back(std::make_pair(qubit_name, qidx));
		}
		else
		{
			auto qubits = qubit_allocations[qubit_name].qubits();

			auto pos = mlirGen(*list.getIndex());
			qubit_value = builder.create<ExtractQubitOp>(
				location, qubit_type, qubits, pos);
			extracted_qubits.insert({ std::make_pair(qubit_name, qidx), qubit_value });
			markPos.push_back(std::make_pair(qubit_name, qidx));
		}
		return qubit_value;
	}

	mlir::Value MLIRGenImpl::mlirGen(NumberExprAST& number)
	{
		auto location = loc(number.loc());
		std::uint64_t index = number.getValue();
		auto integer_attr = mlir::IntegerAttr::get(builder.getI64Type(), index);
		return builder.create<mlir::ConstantOp>(location, integer_attr);
	}

	mlir::FuncOp MLIRGenImpl::mlirGen(PrototypeAST& proto)
	{
		auto location = loc(proto.loc());
		SmallVector<mlir::Type, 4> arg_types(proto.getArgs().size(), getType(VarType{}));
		auto func_type = builder.getFunctionType(arg_types, llvm::None);
		return mlir::FuncOp::create(location, proto.getName(), func_type);
	}

	mlir::LogicalResult MLIRGenImpl::mlirGen(ExprASTList& blockAST)
	{
		ScopedHashTableScope<StringRef, mlir::Value> var_scope(symbolTable);
		for (auto& expr : blockAST)
		{
			mlirGen(*expr);
		}
		return mlir::success();
	}

	mlir::FuncOp MLIRGenImpl::mlirGen(CircuitAST& circuitAST)
	{
		ScopedHashTableScope<StringRef, mlir::Value> var_scope(symbolTable);
		mlir::FuncOp circuit(mlirGen(*circuitAST.getProto()));
		if (!circuit)
		{
			return nullptr;
		}

		// Let's start the body of the function now!
		// In MLIR the entry block of the function is special: it
		// must have the same argument list as the function itself.
		auto& entrBlock = *circuit.addEntryBlock();
		auto protoArgs = circuitAST.getProto()->getArgs();

		// Declare all the function argument in the symbol table.
		for (const auto& name_value : llvm::zip(protoArgs, entrBlock.getArguments()))
		{
			if (mlir::failed(declare(std::get<0>(name_value)->getValue(), 
				std::get<1>(name_value))))
			{
				return nullptr;
			}
		}

		// Set the insertion point in the builder to the beginning
		// of the function body, it will be used throughout the
		// codegen to create operations in this function.
		builder.setInsertionPointToStart(&entrBlock);

		// Emit the body of the function.
		if (mlir::failed(mlirGen(*circuitAST.getBody())))
		{
			circuit.erase();
			return nullptr;
		}
		return circuit;
	}

	mlir::Value MLIRGenImpl::mlirGen(ExprAST& expr)
	{
		switch (expr.getKind())
		{
		case ExprAST::Expr_Cbit:
			return mlirGen(cast<CbitExprAST>(expr));
		case ExprAST::Expr_Qubit:
			return  mlirGen(cast<QubitExprAST>(expr));
		case ExprAST::Expr_Gate:
			return mlirGen(cast<GateExprAST>(expr));
		case ExprAST::Expr_List:
			return mlirGen(cast<ListExprAST>(expr));
		case ExprAST::Expr_Num:
			return mlirGen(cast<NumberExprAST>(expr));
		default:
			mlir::emitError(loc(expr.loc())) << "MLIR codegen encountered an unhandled expr kind '" << Twine(expr.getKind()) << "'";
			return nullptr;
		}
	}

	mlir::Type MLIRGenImpl::getType(ArrayRef<int64_t> shape)
	{
		if (shape.empty())
		{
			return mlir::UnrankedTensorType::get(builder.getF64Type());
		}
	}

	mlir::Type MLIRGenImpl::getType(const VarType& type)
	{
		return getType(type.shape);
	}

};


