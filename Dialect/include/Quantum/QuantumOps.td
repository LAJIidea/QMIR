#ifndef QUANTUM_OPS
#define QUANTUM_OPS

include "QuantumDialect.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

def QubitType : OpaqueType<"quantum", "Qubit", "opaque qubit type">;
def CbitType : OpaqueType<"quantum", "Cbit", "opqaue cbit type">;
def ArrayType : OpaqueType<"quantum", "Array", "opaque array type">;

def Quantum_QallocOp : Quantum_Op<"qalloc", []> {
	let summary = "alloc qubit array.";
	let description = [{
		The `q.qalloc` operation illustrates how to alloc 
		qubit.

		This operation takes an integer argument and a string argument,
		returns a qubit array.

		Example:

		```mlir
		%0 = constant 2 : i32
		// Apply the qalloc operation to %0
		%1 = q.qalloc(%0) { name = q } : !quauntum.Array
		```
	}];

	let arguments = (ins AnyI64Attr:$size, StrAttr:$name);
	let results = (outs ArrayType:$qubits);

	let printer = [{  auto op = *this;	
		p << "q.alloc(" << op.size() << ") {name = " << op.name() << " }";
		p << " : " << op.qubits().getType();
	}];

}

def Quantum_ExtractQubitOp : Quantum_Op<"qextrat", []> {
	let summary = "extrat qubit array.";
	let description = [{
		The `q.extract` operation illustrates how to extrat qubit array.

		This operation takes an array argument and an integer argument,
		returns a single qubit.

		Example:

		```mlir
		%0 = q.qalloc(2) { name = q } : !quauntum.Array
		// Apply the qextrat operation to %0
		%1 = q.extract(%0, %c0_i64) : !quantum.Qubit
		```
	}];

	let arguments = (ins ArrayType:$qreg, AnyInteger:$index);
	let results = (outs QubitType:$qubit);

	let printer = [{  auto op = *this;
		p << "q.extract(" << op.getOperands() << ")";
		p << " : " << op.qubit().getType();
	}];
}

def Quantum_InstOp : Quantum_Op<"inst", [AttrSizedOperandSegments]> {
	let summary = "insert quantum gate.";
	let description = [{
		The `q.gate` operation illustrates how to insert a quantumn 
		gate.

		This operation takes a string argument and a variadic qubit argument
		and a varidic float argument, returns variadic qubit.

		Example:

		```mlir
		%0 = q.qalloc(2) {name = q} : !quantum.Array
		%1 = q.extract(%0, %c0_i64) : !quantum.Qubit
		%2 = q.h(%1) : !quantum.Qubit
		```
	}];

	let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
	let results = (outs Variadic<QubitType>:$result);

	let printer = [{ auto op = *this;
		p << "q." << op.name() << "(" << op.getOperands() << ") : " << op.result().getType();
	}];
}


def Quantum_MeasureOp : Quantum_Op<"measure", []> {
	let summary = "measure qubit status.";
	let description = [{
		The `q.measure` operation illustrates how to measure a qubit.

		This operation takes a qubit argument, returns a cbit;

		Example:

		```mlir
		%0 = q.qalloc(2) {name = q} : !quantum.Array
		%1 = q.extract(%0, %c0_i64) : !quantum.Qubit
		%2 = q.h(%1) : !quantum.Qubit
		%3 = q.measure(%2) : !quantum.Cbit
		```
	}];

	let arguments = (ins QubitType:$qubit);
	let results = (outs CbitType:$cbit);

	let printer = [{ auto op = *this;
		p << "q.measure(" << op.getOperand() << ")";
		p << " : " << op.cbit().getType();
	}];
}

def Quantum_ValueInstOp : Quantum_Op<"value_inst", [AttrSizedOperandSegments]> {
	
	
	let arguments = (ins StrAttr:$name, Variadic<QubitType>:$qubits, Variadic<F64>:$params);
    let results = (outs Optional<CbitType>:$bit);

	let printer = [{ auto op = *this;
		p << "qvs." << op.name() << "(" << op.getOperands() << ") : " << op.bit().getType();
	}];
}

#endif // QUANTUM_OPS