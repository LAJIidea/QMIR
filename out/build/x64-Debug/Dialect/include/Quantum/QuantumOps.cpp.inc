/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Op Definitions                                                             *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifdef GET_OP_LIST
#undef GET_OP_LIST

quantum::ExtractQubitOp,
quantum::InstOp,
quantum::MeasureOp,
quantum::QallocOp,
quantum::ValueInstOp
#endif  // GET_OP_LIST

#ifdef GET_OP_CLASSES
#undef GET_OP_CLASSES


//===----------------------------------------------------------------------===//
// Local Utility Method Definitions
//===----------------------------------------------------------------------===//

namespace quantum {
static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps0(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((isOpaqueTypeWithName(type, "quantum", "Array")))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be opaque array type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps1(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isa<::mlir::IntegerType>()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be integer, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps2(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((isOpaqueTypeWithName(type, "quantum", "Qubit")))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be opaque qubit type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps3(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((isOpaqueTypeWithName(type, "quantum", "Qubit")))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be opaque qubit type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps4(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((type.isF64()))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be 64-bit float, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps5(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((isOpaqueTypeWithName(type, "quantum", "Cbit")))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be opqaue cbit type, but got " << type;
  }
  return ::mlir::success();
}

static ::mlir::LogicalResult __mlir_ods_local_type_constraint_QuantumOps6(::mlir::Operation *op, ::mlir::Type type, ::llvm::StringRef valueKind, unsigned valueGroupStartIndex) {
  if (!((isOpaqueTypeWithName(type, "quantum", "Cbit")))) {
    return op->emitOpError(valueKind) << " #" << valueGroupStartIndex << " must be opqaue cbit type, but got " << type;
  }
  return ::mlir::success();
}

} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::ExtractQubitOp definitions
//===----------------------------------------------------------------------===//

ExtractQubitOpAdaptor::ExtractQubitOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs)  : odsOperands(values), odsAttrs(attrs) {

}

ExtractQubitOpAdaptor::ExtractQubitOpAdaptor(ExtractQubitOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ExtractQubitOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange ExtractQubitOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ExtractQubitOpAdaptor::qreg() {
  return *getODSOperands(0).begin();
}

::mlir::Value ExtractQubitOpAdaptor::index() {
  return *getODSOperands(1).begin();
}

::mlir::LogicalResult ExtractQubitOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::StringRef ExtractQubitOp::getOperationName() {
  return "quantum.qextrat";
}

std::pair<unsigned, unsigned> ExtractQubitOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range ExtractQubitOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ExtractQubitOp::qreg() {
  return *getODSOperands(0).begin();
}

::mlir::Value ExtractQubitOp::index() {
  return *getODSOperands(1).begin();
}

::mlir::MutableOperandRange ExtractQubitOp::qregMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

::mlir::MutableOperandRange ExtractQubitOp::indexMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> ExtractQubitOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range ExtractQubitOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ExtractQubitOp::qubit() {
  return *getODSResults(0).begin();
}

void ExtractQubitOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubit, ::mlir::Value qreg, ::mlir::Value index) {
  odsState.addOperands(qreg);
  odsState.addOperands(index);
  odsState.addTypes(qubit);
}

void ExtractQubitOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value qreg, ::mlir::Value index) {
  odsState.addOperands(qreg);
  odsState.addOperands(index);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void ExtractQubitOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 2u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

void ExtractQubitOp::print(::mlir::OpAsmPrinter &p) {
  auto op = *this;
		p << "q.extract(" << op.getOperands() << ")";
		p << " : " << op.qubit().getType();
}

::mlir::LogicalResult ExtractQubitOp::verify() {
  if (failed(ExtractQubitOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps0(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps1(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps2(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::InstOp definitions
//===----------------------------------------------------------------------===//

InstOpAdaptor::InstOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs)  : odsOperands(values), odsAttrs(attrs) {

}

InstOpAdaptor::InstOpAdaptor(InstOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> InstOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  assert(odsAttrs && "missing segment size attribute for op");
  auto sizeAttr = odsAttrs.get("operand_segment_sizes").cast<::mlir::DenseIntElementsAttr>();

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += (*(sizeAttr.begin() + i)).getZExtValue();
  unsigned size = (*(sizeAttr.begin() + index)).getZExtValue();
  return {start, size};
}

::mlir::ValueRange InstOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::ValueRange InstOpAdaptor::qubits() {
  return getODSOperands(0);
}

::mlir::ValueRange InstOpAdaptor::params() {
  return getODSOperands(1);
}

::mlir::StringAttr InstOpAdaptor::name() {
  assert(odsAttrs && "no attributes when constructing adapter");
  ::mlir::StringAttr attr = odsAttrs.get("name").cast<::mlir::StringAttr>();
  return attr;
}

::mlir::LogicalResult InstOpAdaptor::verify(::mlir::Location loc) {
  {
    auto sizeAttr = odsAttrs.get("operand_segment_sizes").cast<::mlir::DenseIntElementsAttr>();
    auto numElements = sizeAttr.getType().cast<::mlir::ShapedType>().getNumElements();
    if (numElements != 2)
      return emitError(loc, "'operand_segment_sizes' attribute for specifying operand segments "
                       "must have 2 elements, but got ") << numElements;
  }
    {
  auto tblgen_name = odsAttrs.get("name");
  if (!tblgen_name) return emitError(loc, "'quantum.inst' op ""requires attribute 'name'");
    if (!((tblgen_name.isa<::mlir::StringAttr>()))) return emitError(loc, "'quantum.inst' op ""attribute 'name' failed to satisfy constraint: string attribute");
  }
  return ::mlir::success();
}

::llvm::StringRef InstOp::getOperationName() {
  return "quantum.inst";
}

std::pair<unsigned, unsigned> InstOp::getODSOperandIndexAndLength(unsigned index) {
  auto sizeAttr = (*this)->getAttrOfType<::mlir::DenseIntElementsAttr>("operand_segment_sizes");

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += (*(sizeAttr.begin() + i)).getZExtValue();
  unsigned size = (*(sizeAttr.begin() + index)).getZExtValue();
  return {start, size};
}

::mlir::Operation::operand_range InstOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range InstOp::qubits() {
  return getODSOperands(0);
}

::mlir::Operation::operand_range InstOp::params() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange InstOp::qubitsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(0u, *getOperation()->getAttrDictionary().getNamed("operand_segment_sizes")));
}

::mlir::MutableOperandRange InstOp::paramsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(1u, *getOperation()->getAttrDictionary().getNamed("operand_segment_sizes")));
}

std::pair<unsigned, unsigned> InstOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::result_range InstOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::result_range InstOp::result() {
  return getODSResults(0);
}

::mlir::StringAttr InstOp::nameAttr() {
  return (*this)->getAttr("name").template cast<::mlir::StringAttr>();
}

::llvm::StringRef InstOp::name() {
  auto attr = nameAttr();
  return attr.getValue();
}

void InstOp::nameAttr(::mlir::StringAttr attr) {
  (*this)->setAttr("name", attr);
}

void InstOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params) {
  odsState.addOperands(qubits);
  odsState.addOperands(params);
  odsState.addAttribute("operand_segment_sizes", odsBuilder.getI32VectorAttr({static_cast<int32_t>(qubits.size()), static_cast<int32_t>(params.size())}));
  odsState.addAttribute("name", name);
  odsState.addTypes(result);
}

void InstOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange result, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params) {
  odsState.addOperands(qubits);
  odsState.addOperands(params);
  odsState.addAttribute("operand_segment_sizes", odsBuilder.getI32VectorAttr({static_cast<int32_t>(qubits.size()), static_cast<int32_t>(params.size())}));
  odsState.addAttribute("name", odsBuilder.getStringAttr(name));
  odsState.addTypes(result);
}

void InstOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

void InstOp::print(::mlir::OpAsmPrinter &p) {
  auto op = *this;
		p << "q." << op.name() << "(" << op.getOperands() << ") : " << op.result().getType();
}

::mlir::LogicalResult InstOp::verify() {
  if (failed(InstOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps3(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps4(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps3(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::MeasureOp definitions
//===----------------------------------------------------------------------===//

MeasureOpAdaptor::MeasureOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs)  : odsOperands(values), odsAttrs(attrs) {

}

MeasureOpAdaptor::MeasureOpAdaptor(MeasureOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> MeasureOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange MeasureOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::Value MeasureOpAdaptor::qubit() {
  return *getODSOperands(0).begin();
}

::mlir::LogicalResult MeasureOpAdaptor::verify(::mlir::Location loc) {
  return ::mlir::success();
}

::llvm::StringRef MeasureOp::getOperationName() {
  return "quantum.measure";
}

std::pair<unsigned, unsigned> MeasureOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range MeasureOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value MeasureOp::qubit() {
  return *getODSOperands(0).begin();
}

::mlir::MutableOperandRange MeasureOp::qubitMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second);
}

std::pair<unsigned, unsigned> MeasureOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range MeasureOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value MeasureOp::cbit() {
  return *getODSResults(0).begin();
}

void MeasureOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type cbit, ::mlir::Value qubit) {
  odsState.addOperands(qubit);
  odsState.addTypes(cbit);
}

void MeasureOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::Value qubit) {
  odsState.addOperands(qubit);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void MeasureOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 1u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

void MeasureOp::print(::mlir::OpAsmPrinter &p) {
  auto op = *this;
		p << "q.measure(" << op.getOperand() << ")";
		p << " : " << op.cbit().getType();
}

::mlir::LogicalResult MeasureOp::verify() {
  if (failed(MeasureOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps2(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps5(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::QallocOp definitions
//===----------------------------------------------------------------------===//

QallocOpAdaptor::QallocOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs)  : odsOperands(values), odsAttrs(attrs) {

}

QallocOpAdaptor::QallocOpAdaptor(QallocOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> QallocOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::ValueRange QallocOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::IntegerAttr QallocOpAdaptor::size() {
  assert(odsAttrs && "no attributes when constructing adapter");
  ::mlir::IntegerAttr attr = odsAttrs.get("size").cast<::mlir::IntegerAttr>();
  return attr;
}

::mlir::StringAttr QallocOpAdaptor::name() {
  assert(odsAttrs && "no attributes when constructing adapter");
  ::mlir::StringAttr attr = odsAttrs.get("name").cast<::mlir::StringAttr>();
  return attr;
}

::mlir::LogicalResult QallocOpAdaptor::verify(::mlir::Location loc) {
  {
  auto tblgen_size = odsAttrs.get("size");
  if (!tblgen_size) return emitError(loc, "'quantum.qalloc' op ""requires attribute 'size'");
    if (!(((tblgen_size.isa<::mlir::IntegerAttr>())) && ((tblgen_size.cast<::mlir::IntegerAttr>().getType().isInteger(64))))) return emitError(loc, "'quantum.qalloc' op ""attribute 'size' failed to satisfy constraint: 64-bit integer attribute");
  }
  {
  auto tblgen_name = odsAttrs.get("name");
  if (!tblgen_name) return emitError(loc, "'quantum.qalloc' op ""requires attribute 'name'");
    if (!((tblgen_name.isa<::mlir::StringAttr>()))) return emitError(loc, "'quantum.qalloc' op ""attribute 'name' failed to satisfy constraint: string attribute");
  }
  return ::mlir::success();
}

::llvm::StringRef QallocOp::getOperationName() {
  return "quantum.qalloc";
}

std::pair<unsigned, unsigned> QallocOp::getODSOperandIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::operand_range QallocOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

std::pair<unsigned, unsigned> QallocOp::getODSResultIndexAndLength(unsigned index) {
  return {index, 1};
}

::mlir::Operation::result_range QallocOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value QallocOp::qubits() {
  return *getODSResults(0).begin();
}

::mlir::IntegerAttr QallocOp::sizeAttr() {
  return (*this)->getAttr("size").template cast<::mlir::IntegerAttr>();
}

::llvm::APInt QallocOp::size() {
  auto attr = sizeAttr();
  return attr.getValue();
}

::mlir::StringAttr QallocOp::nameAttr() {
  return (*this)->getAttr("name").template cast<::mlir::StringAttr>();
}

::llvm::StringRef QallocOp::name() {
  auto attr = nameAttr();
  return attr.getValue();
}

void QallocOp::sizeAttr(::mlir::IntegerAttr attr) {
  (*this)->setAttr("size", attr);
}

void QallocOp::nameAttr(::mlir::StringAttr attr) {
  (*this)->setAttr("name", attr);
}

void QallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubits, ::mlir::IntegerAttr size, ::mlir::StringAttr name) {
  odsState.addAttribute("size", size);
  odsState.addAttribute("name", name);
  odsState.addTypes(qubits);
}

void QallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr size, ::mlir::StringAttr name) {
  odsState.addAttribute("size", size);
  odsState.addAttribute("name", name);
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void QallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::Type qubits, ::mlir::IntegerAttr size, ::llvm::StringRef name) {
  odsState.addAttribute("size", size);
  odsState.addAttribute("name", odsBuilder.getStringAttr(name));
  odsState.addTypes(qubits);
}

void QallocOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::IntegerAttr size, ::llvm::StringRef name) {
  odsState.addAttribute("size", size);
  odsState.addAttribute("name", odsBuilder.getStringAttr(name));
  assert(resultTypes.size() == 1u && "mismatched number of results");
  odsState.addTypes(resultTypes);
}

void QallocOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  assert(operands.size() == 0u && "mismatched number of parameters");
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  assert(resultTypes.size() == 1u && "mismatched number of return types");
  odsState.addTypes(resultTypes);
}

void QallocOp::print(::mlir::OpAsmPrinter &p) {
  auto op = *this;	
		p << "q.alloc(" << op.size() << ") {name = " << op.name() << " }";
		p << " : " << op.qubits().getType();
}

::mlir::LogicalResult QallocOp::verify() {
  if (failed(QallocOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps0(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

} // namespace quantum
namespace quantum {

//===----------------------------------------------------------------------===//
// quantum::ValueInstOp definitions
//===----------------------------------------------------------------------===//

ValueInstOpAdaptor::ValueInstOpAdaptor(::mlir::ValueRange values, ::mlir::DictionaryAttr attrs)  : odsOperands(values), odsAttrs(attrs) {

}

ValueInstOpAdaptor::ValueInstOpAdaptor(ValueInstOp&op)  : odsOperands(op->getOperands()), odsAttrs(op->getAttrDictionary()) {

}

std::pair<unsigned, unsigned> ValueInstOpAdaptor::getODSOperandIndexAndLength(unsigned index) {
  assert(odsAttrs && "missing segment size attribute for op");
  auto sizeAttr = odsAttrs.get("operand_segment_sizes").cast<::mlir::DenseIntElementsAttr>();

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += (*(sizeAttr.begin() + i)).getZExtValue();
  unsigned size = (*(sizeAttr.begin() + index)).getZExtValue();
  return {start, size};
}

::mlir::ValueRange ValueInstOpAdaptor::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(odsOperands.begin(), valueRange.first),
           std::next(odsOperands.begin(), valueRange.first + valueRange.second)};
}

::mlir::ValueRange ValueInstOpAdaptor::qubits() {
  return getODSOperands(0);
}

::mlir::ValueRange ValueInstOpAdaptor::params() {
  return getODSOperands(1);
}

::mlir::StringAttr ValueInstOpAdaptor::name() {
  assert(odsAttrs && "no attributes when constructing adapter");
  ::mlir::StringAttr attr = odsAttrs.get("name").cast<::mlir::StringAttr>();
  return attr;
}

::mlir::LogicalResult ValueInstOpAdaptor::verify(::mlir::Location loc) {
  {
    auto sizeAttr = odsAttrs.get("operand_segment_sizes").cast<::mlir::DenseIntElementsAttr>();
    auto numElements = sizeAttr.getType().cast<::mlir::ShapedType>().getNumElements();
    if (numElements != 2)
      return emitError(loc, "'operand_segment_sizes' attribute for specifying operand segments "
                       "must have 2 elements, but got ") << numElements;
  }
    {
  auto tblgen_name = odsAttrs.get("name");
  if (!tblgen_name) return emitError(loc, "'quantum.value_inst' op ""requires attribute 'name'");
    if (!((tblgen_name.isa<::mlir::StringAttr>()))) return emitError(loc, "'quantum.value_inst' op ""attribute 'name' failed to satisfy constraint: string attribute");
  }
  return ::mlir::success();
}

::llvm::StringRef ValueInstOp::getOperationName() {
  return "quantum.value_inst";
}

std::pair<unsigned, unsigned> ValueInstOp::getODSOperandIndexAndLength(unsigned index) {
  auto sizeAttr = (*this)->getAttrOfType<::mlir::DenseIntElementsAttr>("operand_segment_sizes");

  unsigned start = 0;
  for (unsigned i = 0; i < index; ++i)
    start += (*(sizeAttr.begin() + i)).getZExtValue();
  unsigned size = (*(sizeAttr.begin() + index)).getZExtValue();
  return {start, size};
}

::mlir::Operation::operand_range ValueInstOp::getODSOperands(unsigned index) {
  auto valueRange = getODSOperandIndexAndLength(index);
  return {std::next(getOperation()->operand_begin(), valueRange.first),
           std::next(getOperation()->operand_begin(), valueRange.first + valueRange.second)};
}

::mlir::Operation::operand_range ValueInstOp::qubits() {
  return getODSOperands(0);
}

::mlir::Operation::operand_range ValueInstOp::params() {
  return getODSOperands(1);
}

::mlir::MutableOperandRange ValueInstOp::qubitsMutable() {
  auto range = getODSOperandIndexAndLength(0);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(0u, *getOperation()->getAttrDictionary().getNamed("operand_segment_sizes")));
}

::mlir::MutableOperandRange ValueInstOp::paramsMutable() {
  auto range = getODSOperandIndexAndLength(1);
  return ::mlir::MutableOperandRange(getOperation(), range.first, range.second, ::mlir::MutableOperandRange::OperandSegment(1u, *getOperation()->getAttrDictionary().getNamed("operand_segment_sizes")));
}

std::pair<unsigned, unsigned> ValueInstOp::getODSResultIndexAndLength(unsigned index) {
  bool isVariadic[] = {true};
  int prevVariadicCount = 0;
  for (unsigned i = 0; i < index; ++i)
    if (isVariadic[i]) ++prevVariadicCount;

  // Calculate how many dynamic values a static variadic operand corresponds to.
  // This assumes all static variadic operands have the same dynamic value count.
  int variadicSize = (getOperation()->getNumResults() - 0) / 1;
  // `index` passed in as the parameter is the static index which counts each
  // operand (variadic or not) as size 1. So here for each previous static variadic
  // operand, we need to offset by (variadicSize - 1) to get where the dynamic
  // value pack for this static operand starts.
  int start = index + (variadicSize - 1) * prevVariadicCount;
  int size = isVariadic[index] ? variadicSize : 1;
  return {start, size};
}

::mlir::Operation::result_range ValueInstOp::getODSResults(unsigned index) {
  auto valueRange = getODSResultIndexAndLength(index);
  return {std::next(getOperation()->result_begin(), valueRange.first),
           std::next(getOperation()->result_begin(), valueRange.first + valueRange.second)};
}

::mlir::Value ValueInstOp::bit() {
  auto results = getODSResults(0);
  return results.empty() ? ::mlir::Value() : *results.begin();
}

::mlir::StringAttr ValueInstOp::nameAttr() {
  return (*this)->getAttr("name").template cast<::mlir::StringAttr>();
}

::llvm::StringRef ValueInstOp::name() {
  auto attr = nameAttr();
  return attr.getValue();
}

void ValueInstOp::nameAttr(::mlir::StringAttr attr) {
  (*this)->setAttr("name", attr);
}

void ValueInstOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type bit, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params) {
  odsState.addOperands(qubits);
  odsState.addOperands(params);
  odsState.addAttribute("operand_segment_sizes", odsBuilder.getI32VectorAttr({static_cast<int32_t>(qubits.size()), static_cast<int32_t>(params.size())}));
  odsState.addAttribute("name", name);
  if (bit)
    odsState.addTypes(bit);
}

void ValueInstOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::StringAttr name, ::mlir::ValueRange qubits, ::mlir::ValueRange params) {
  odsState.addOperands(qubits);
  odsState.addOperands(params);
  odsState.addAttribute("operand_segment_sizes", odsBuilder.getI32VectorAttr({static_cast<int32_t>(qubits.size()), static_cast<int32_t>(params.size())}));
  odsState.addAttribute("name", name);
  odsState.addTypes(resultTypes);
}

void ValueInstOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, /*optional*/::mlir::Type bit, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params) {
  odsState.addOperands(qubits);
  odsState.addOperands(params);
  odsState.addAttribute("operand_segment_sizes", odsBuilder.getI32VectorAttr({static_cast<int32_t>(qubits.size()), static_cast<int32_t>(params.size())}));
  odsState.addAttribute("name", odsBuilder.getStringAttr(name));
  if (bit)
    odsState.addTypes(bit);
}

void ValueInstOp::build(::mlir::OpBuilder &odsBuilder, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::llvm::StringRef name, ::mlir::ValueRange qubits, ::mlir::ValueRange params) {
  odsState.addOperands(qubits);
  odsState.addOperands(params);
  odsState.addAttribute("operand_segment_sizes", odsBuilder.getI32VectorAttr({static_cast<int32_t>(qubits.size()), static_cast<int32_t>(params.size())}));
  odsState.addAttribute("name", odsBuilder.getStringAttr(name));
  odsState.addTypes(resultTypes);
}

void ValueInstOp::build(::mlir::OpBuilder &, ::mlir::OperationState &odsState, ::mlir::TypeRange resultTypes, ::mlir::ValueRange operands, ::llvm::ArrayRef<::mlir::NamedAttribute> attributes) {
  odsState.addOperands(operands);
  odsState.addAttributes(attributes);
  odsState.addTypes(resultTypes);
}

void ValueInstOp::print(::mlir::OpAsmPrinter &p) {
  auto op = *this;
		p << "qvs." << op.name() << "(" << op.getOperands() << ") : " << op.bit().getType();
}

::mlir::LogicalResult ValueInstOp::verify() {
  if (failed(ValueInstOpAdaptor(*this).verify((*this)->getLoc()))) return ::mlir::failure();
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSOperands(0);
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps3(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
    auto valueGroup1 = getODSOperands(1);
    for (::mlir::Value v : valueGroup1) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps4(getOperation(), v.getType(), "operand", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  {
    unsigned index = 0; (void)index;
    auto valueGroup0 = getODSResults(0);
    if (valueGroup0.size() > 1)
      return emitOpError("result group starting at #") << index << " requires 0 or 1 element, but found " << valueGroup0.size();
    for (::mlir::Value v : valueGroup0) {
      if (::mlir::failed(__mlir_ods_local_type_constraint_QuantumOps6(getOperation(), v.getType(), "result", index)))
        return ::mlir::failure();
      ++index;
    }
  }
  return ::mlir::success();
}

} // namespace quantum

#endif  // GET_OP_CLASSES

