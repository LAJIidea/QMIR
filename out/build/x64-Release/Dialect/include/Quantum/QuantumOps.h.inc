/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Declarations                                                            *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#if defined(GET_OP_CLASSES) || defined(GET_OP_FWD_DEFINES)
#undef GET_OP_FWD_DEFINES
class ExtractQubitOp;
class InstOp;
class MeasureOp;
class QallocOp;
class ValueInstOp;
#endif

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// quantum::ExtractQubitOp declarations
//===----------------------------------------------------------------------===//

class ExtractQubitOpAdaptor {
public:
  ExtractQubitOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr);
  ExtractQubitOpAdaptor(ExtractQubitOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value qreg();
  ::mlir::Value index();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class ExtractQubitOp : public ::mlir::Op<ExtractQubitOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::NOperands<2>::Impl> {
public:
  using Op::Op;
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
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::Value qreg, ::mlir::Value index);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// quantum::InstOp declarations
//===----------------------------------------------------------------------===//

class InstOpAdaptor {
public:
  InstOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs);
  InstOpAdaptor(InstOp& op);
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
class InstOp : public ::mlir::Op<InstOp, OpTrait::ZeroRegion, OpTrait::VariadicResults, OpTrait::ZeroSuccessor, OpTrait::VariadicOperands, OpTrait::AttrSizedOperandSegments> {
public:
  using Op::Op;
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
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> result, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> result, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// quantum::MeasureOp declarations
//===----------------------------------------------------------------------===//

class MeasureOpAdaptor {
public:
  MeasureOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr);
  MeasureOpAdaptor(MeasureOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::Value qubit();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class MeasureOp : public ::mlir::Op<MeasureOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::OneOperand> {
public:
  using Op::Op;
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
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::Value qubit);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// quantum::QallocOp declarations
//===----------------------------------------------------------------------===//

class QallocOpAdaptor {
public:
  QallocOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs = nullptr);
  QallocOpAdaptor(QallocOp& op);
  std::pair<unsigned, unsigned> getODSOperandIndexAndLength(unsigned index);
  ::mlir::ValueRange getODSOperands(unsigned index);
  ::mlir::IntegerAttr size();
  ::mlir::StringAttr name();
  ::mlir::LogicalResult verify(::mlir::Location loc);

private:
  ::mlir::ValueRange odsOperands;
  ::mlir::DictionaryAttr odsAttrs;
};
class QallocOp : public ::mlir::Op<QallocOp, OpTrait::ZeroRegion, OpTrait::OneResult, OpTrait::ZeroSuccessor, OpTrait::ZeroOperands> {
public:
  using Op::Op;
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
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::IntegerAttr size, ::mlir::StringAttr name);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubits, ::mlir::IntegerAttr size, ::llvm::StringRef name);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::IntegerAttr size, ::llvm::StringRef name);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};

//===----------------------------------------------------------------------===//
// quantum::ValueInstOp declarations
//===----------------------------------------------------------------------===//

class ValueInstOpAdaptor {
public:
  ValueInstOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs);
  ValueInstOpAdaptor(ValueInstOp& op);
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
class ValueInstOp : public ::mlir::Op<ValueInstOp, OpTrait::ZeroRegion, OpTrait::VariadicResults, OpTrait::ZeroSuccessor, OpTrait::VariadicOperands, OpTrait::AttrSizedOperandSegments> {
public:
  using Op::Op;
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
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type bit, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params);
  static void build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::llvm::ArrayRef<::mlir::Type> resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes = {});
  void print(::mlir::OpAsmPrinter &p);
  ::mlir::LogicalResult verify();
};

#endif  // GET_OP_CLASSES

