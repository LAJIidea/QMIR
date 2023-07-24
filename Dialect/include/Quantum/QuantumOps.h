#ifndef DIALECT_QUANTUMOPS_H
#define DIALECT_QUANTUMOPS_H

#include "mlir/IR/OpDefinition.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

namespace mlir
{
#define GET_OP_CLASSES
#include "Quantum/QuantumOps.h.inc"
} // namespace mlir

#endif