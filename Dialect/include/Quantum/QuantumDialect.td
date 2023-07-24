#ifndef QUANTUM_DIALECT
#define QUANTUM_DIALECT

include "mlir/IR/OpBase.td"

def Quantum_Dialect : Dialect {
	let name = "quantum";
	let summary = "A quantum MLIR dialect.";
	let description = [{
		This dialect is a demo for quantum compiler.
	}];
	let cppNamespace = "quantum";
}

class Quantum_Op<string mnemonic, list<OpTrait> traits = []> : 
		Op<Quantum_Dialect, mnemonic, traits>;

#endif // QUANTUM_DIALECT