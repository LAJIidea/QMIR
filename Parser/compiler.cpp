#include "Parse.h"
#include "Quantum/QuantumDialect.h"
#include "MLIRGen.h"
#include "PairRemovePass.h"

#include <mlir/IR/AsmState.h>
#include <mlir/IR/MLIRContext.h>
//#include <mlir/IR/Module.h>
#include <mlir/IR/Verifier.h>
#include <mlir/Pass/Pass.h>
#include <mlir/Parser.h>
#include <mlir/Pass/PassManager.h>
#include <mlir/Transforms/Passes.h>
#include <mlir/Dialect/StandardOps/IR/Ops.h>

#include <llvm/ADT/StringRef.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/ErrorOr.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_os_ostream.h>

using namespace qmir;
namespace cl = llvm::cl;

static cl::opt<std::string> inputFilename(cl::Positional, cl::desc("<input toy file>"), 
	cl::init("-"), cl::value_desc("filename"));

static cl::opt<bool> enableOpt("opt", cl::desc("Enable optimizations"));

std::unique_ptr<qmir::ModuleAST> parseInputFile(llvm::StringRef filename)
{
	llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> fileOrErr =
		llvm::MemoryBuffer::getFileOrSTDIN(filename);
	if (std::error_code ec = fileOrErr.getError())
	{
		llvm::errs() << "Could not open input file: " << ec.message() << "\n";
		return nullptr;
	}
	auto buffer = fileOrErr.get()->getBuffer();
	LexerBuffer lexer(buffer.begin(), buffer.end(), std::string(filename));
	Parser parser(lexer);
	return parser.parseModule();
}

int loadMLIR(llvm::SourceMgr& sourceMgr, mlir::MLIRContext& context,
	mlir::OwningModuleRef& module)
{
	auto moduleAST = parseInputFile(inputFilename);
	if (!moduleAST)
	{
		return 6;
	}
	MLIRGenImpl impl(context);
	module = impl.mlirGen(*moduleAST);
	return !module ? 1 : 0;
}

int dumpMLIR()
{
	mlir::MLIRContext context;
    // Load our Dialect in this MLIR Context
    context.getOrLoadDialect<mlir::quantum::QuantumDialect>();
    context.loadDialect<mlir::StandardOpsDialect>();
	mlir::OwningModuleRef module;
	llvm::SourceMgr sourceMgr;
	mlir::SourceMgrDiagnosticHandler sourceMrgHandler(sourceMgr, &context);
	if (int error = loadMLIR(sourceMgr, context, module))
	{
		return error;
	}

	if (enableOpt)
	{
		mlir::PassManager pm(&context);

		mlir::applyPassManagerCLOptions(pm);

		pm.addPass(std::make_unique<SingleQubitPairRemovePass>());
		pm.addPass(std::make_unique<CNOTIdentityPairRemovalPass>());
		auto module_op = (*module).getOperation();
		pm.run(*module);
	}

	module->dump();
	return 0;
}

int main(int argc, char** argv)
{
	mlir::registerAsmPrinterCLOptions();
	mlir::registerMLIRContextCLOptions();
	mlir::registerPassManagerCLOptions();

	cl::ParseCommandLineOptions(argc, argv, "qmir compiler\n");

	return dumpMLIR();
}