#include "PairRemovePass.h"
#include <mlir/Dialect/LLVMIR/LLVMDialect.h>
#include <mlir/Dialect/StandardOps/IR/Ops.h>
#include <mlir/IR/Matchers.h>
#include <mlir/IR/PatternMatch.h>
#include <mlir/Pass/Pass.h>
#include <mlir/Target/LLVMIR.h>
#include <mlir/Transforms/DialectConversion.h>
#include <mlir/Transforms/Passes.h>
#include <iostream>

namespace qmir
{
	void SingleQubitPairRemovePass::runOnOperation()
	{
		// Walk the operations within in the function.
		std::vector<mlir::quantum::InstOp> deadOps;
		getOperation().walk([&](mlir::quantum::InstOp op)
		{
			if (std::find(deadOps.begin(), deadOps.end(), op) != deadOps.end())
			{
				// Skip this op since it was merged (forward search)
				return;
			}

			auto inst_name = op.name();
			auto return_value = *op.result().begin();
			if (return_value.hasOneUse())
			{
				auto user = *return_value.user_begin();
				if (auto next_inst = 
						dyn_cast_or_null<mlir::quantum::InstOp>(user))
				{
					// check that it is one of our known id pairs
					if (should_remove(next_inst.name().str(), inst_name.str()))
					{
						// need to get users of next_inst and point them to use op.getOperands
						(*next_inst.result_begin()).replaceAllUsesWith(op.getOperand(0));
						deadOps.emplace_back(op);
						deadOps.emplace_back(next_inst);
					}
				}
			}
		});

		for (auto &op : deadOps)
		{
			// todo wait
			op.erase();
		}
	}

	bool SingleQubitPairRemovePass::should_remove(std::string name1, std::string name2) const
	{
		if (search_gates.count(name1))
		{
			return search_gates.at(name1) == name2;
		}
		return false;
	}

	void CNOTIdentityPairRemovalPass::runOnOperation()
	{
		std::vector<mlir::quantum::InstOp> deadOps;
		getOperation().walk([&](mlir::quantum::InstOp op)
		{
			if (std::find(deadOps.begin(), deadOps.end(), op) != deadOps.end())
			{
				// Skip this op since it was merged(forward search)
				return;
			}

			auto inst_name = op.name();

			if (inst_name != "CNOT")
			{
				return;
			}

			// Get the src ret qubit and tgt ret qubit
			auto src_return_val = op.result().front();
			auto tgt_return_val = op.result().back();

			// Make sure they are used
			if (src_return_val.hasOneUse() && tgt_return_val.hasOneUse())
			{
				// get the users of these values
				auto src_user = *src_return_val.user_begin();
				auto tgt_user = *tgt_return_val.user_begin();

				// Cast them to InstOps
				auto next_inst =
					dyn_cast_or_null<mlir::quantum::InstOp>(src_user);
				auto tmp_tgt =
					dyn_cast_or_null<mlir::quantum::InstOp>(tgt_user);
				if (!next_inst || !tmp_tgt)
				{
					// not inst ops
					return;
				}

				// We want the case where src_user and tgt_user are the same
				if (next_inst.getOperation() != tmp_tgt.getOperation())
				{
					return;
				}

				// Need src_return_val to map to next_inst operand 0,
				// and tgt_return_val to map to next_inst operand 1.
				if (next_inst.getOperand(0) != src_return_val &&
					next_inst.getOperand(1) != tgt_return_val)
				{
					return;
				}

				// They are the same operation,
				auto next_inst_result_0 = next_inst.result().front();
				auto next_inst_result_1 = next_inst.result().back();
				next_inst_result_0.replaceAllUsesWith(op.getOperand(0));
				next_inst_result_1.replaceAllUsesWith(op.getOperand(1));

				// Remove the identity pair
				deadOps.emplace_back(op);
				deadOps.emplace_back(src_user);
			}
		});

		for (auto &op :deadOps)
		{
			
			op.erase();
		}
	}

}
