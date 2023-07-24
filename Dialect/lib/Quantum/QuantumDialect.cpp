#include "Quantum/QuantumDialect.h"
#include "Quantum/QuantumOps.h"

using namespace mlir;
using namespace mlir::quantum;

void QuantumDialect::initialize() {
    addOperations<
#define GET_OP_LIST
#include "Quantum/QuantumOps.cpp.inc"
        >();
//    addInterfaces<>()
}
