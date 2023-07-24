/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if defined(GET_OP_CLASSES) || defined(GET_OP_FWD_DEFINES)
#undef GET_OP_FWD_DEFINES
namespace quantum {
class ExtractQubitOp;
} // namespace quantum
namespace quantum {
class InstOp;
} // namespace quantum
namespace quantum {
class MeasureOp;
} // namespace quantum
namespace quantum {
class QallocOp;
} // namespace quantum
namespace quantum {
class ValueInstOp;
} // namespace quantum
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES

namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::ExtractQubitOp declarations
//===----------------------------------------------------------------------===//

class ExtractQubitOpAdaptor {
public:
  ExtractQubitOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr);
  ExtractQubitOpAdaptor(ExtractQubitOp&op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value qreg();
  ::mlir::Value index();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class ExtractQubitOp : public ::mlir::Op<ExtractQubitOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::OpaqueType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ExtractQubitOpAdaptor;
  static ::llvm::StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value qreg();
  ::mlir::Value index();
  ::mlir::MutableOperandRange qregMutable();
  ::mlir::MutableOperandRange indexMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value qubit();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubit, ::mlir::Value qreg, ::mlir::Value index);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value qreg, ::mlir::Value index);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};
} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::InstOp declarations
//===----------------------------------------------------------------------===//

class InstOpAdaptor {
public:
  InstOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs);
  InstOpAdaptor(InstOp&op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange qubits();
  ::mlir::ValueRange params();
  ::mlir::StringAttr name();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class InstOp : public ::mlir::Op<InstOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::AttrSizedOperandSegments> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = InstOpAdaptor;
  static ::llvm::StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range qubits();
  ::mlir::Operation::operand_range params();
  ::mlir::MutableOperandRange qubitsMutable();
  ::mlir::MutableOperandRange paramsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Operation::result_range result();
  ::mlir::StringAttr nameAttr();
  ::llvm::StringRef name();
  void nameAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};
} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::MeasureOp declarations
//===----------------------------------------------------------------------===//

class MeasureOpAdaptor {
public:
  MeasureOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr);
  MeasureOpAdaptor(MeasureOp&op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value qubit();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class MeasureOp : public ::mlir::Op<MeasureOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::OpaqueType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::OneOperand> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = MeasureOpAdaptor;
  static ::llvm::StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Value qubit();
  ::mlir::MutableOperandRange qubitMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value cbit();
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type cbit, ::mlir::Value qubit);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value qubit);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};
} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::QallocOp declarations
//===----------------------------------------------------------------------===//

class QallocOpAdaptor {
public:
  QallocOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr);
  QallocOpAdaptor(QallocOp&op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::IntegerAttr size();
  ::mlir::StringAttr name();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class QallocOp : public ::mlir::Op<QallocOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::OneResult, ::mlir::OpTrait::OneTypedResult<::mlir::OpaqueType>::Impl, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::ZeroOperands> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = QallocOpAdaptor;
  static ::llvm::StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value qubits();
  ::mlir::IntegerAttr sizeAttr();
  ::llvm::APInt size();
  ::mlir::StringAttr nameAttr();
  ::llvm::StringRef name();
  void sizeAttr(::mlir::IntegerAttr attr);
  void nameAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubits, ::mlir::IntegerAttr size, ::mlir::StringAttr name);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr size, ::mlir::StringAttr name);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubits, ::mlir::IntegerAttr size, ::llvm::StringRef name);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr size, ::llvm::StringRef name);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};
} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::ValueInstOp declarations
//===----------------------------------------------------------------------===//

class ValueInstOpAdaptor {
public:
  ValueInstOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs);
  ValueInstOpAdaptor(ValueInstOp&op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::ValueRange qubits();
  ::mlir::ValueRange params();
  ::mlir::StringAttr name();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class ValueInstOp : public ::mlir::Op<ValueInstOp, ::mlir::OpTrait::ZeroRegion, ::mlir::OpTrait::VariadicResults, ::mlir::OpTrait::ZeroSuccessor, ::mlir::OpTrait::VariadicOperands, ::mlir::OpTrait::AttrSizedOperandSegments> {
public:
  using Op::Op;
  using Op::print;
  using Adaptor = ValueInstOpAdaptor;
  static ::llvm::StringRef getOperationName();
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::Operation::operand_range getODSOperands(unsigned index);
  ::mlir::Operation::operand_range qubits();
  ::mlir::Operation::operand_range params();
  ::mlir::MutableOperandRange qubitsMutable();
  ::mlir::MutableOperandRange paramsMutable();
  std::pair<unsigned, unsigned> getODSResultIndexAndLength(unsigned index);
  ::mlir::Operation::result_range getODSResults(unsigned index);
  ::mlir::Value bit();
  ::mlir::StringAttr nameAttr();
  ::llvm::StringRef name();
  void nameAttr(::mlir::StringAttr attr);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type bit, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type bit, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};
} // namespace quantum

#endif  // GET_OP_CLASSES

