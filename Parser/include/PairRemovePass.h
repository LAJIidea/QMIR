#include "Quantum/QuantumOps.h"
#include <mlir/Pass/Pass.h>
#include <mlir/Pass/PassManager.h>
#include <mlir/Target/LLVMIR.h>
#include <mlir/Transforms/DialectConversion.h>
#include <mlir/Transforms/Passes.h>
#include <map>

using namespace mlir;

namespace qmir
{
	struct SingleQubitPairRemovePass
		: public PassWrapper<SingleQubitPairRemovePass,
							 OperationPass<ModuleOp>>
	{
		void runOnOperation() final;
		SingleQubitPairRemovePass() {}

	protected:
		std::map<std::string, std::string> search_gates{ {"X", "X"}, {"H", "H"} };
		bool should_remove(std::string name1, std::string name2) const;
	};

	struct CNOTIdentityPairRemovalPass
		: public PassWrapper<CNOTIdentityPairRemovalPass, OperationPass<ModuleOp>>
	{
		void runOnOperation() final;
		CNOTIdentityPairRemovalPass() {}
	};
	

}
