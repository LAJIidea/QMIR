#include "Quantum/QuantumOps.h"
#include "Quantum/QuantumDialect.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/Builders.h"

namespace mlir
{
    bool isOpaqueTypeWithName(mlir::Type type, std::string dialect,
                              std::string type_name)
    {
        if (type.isa<mlir::OpaqueType>() && dialect == "quantum")
        {
            if (type_name == "Qubit" || type_name == "Array" || type_name == "Cbit")
            {
                return true;
            }
        }
        return false;
    }

#define GET_OP_CLASSES
#include "Quantum/QuantumOps.cpp.inc"
} // namespace mlir