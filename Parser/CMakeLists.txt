cmake_minimum_required (VERSION 3.10)

include_directories(include)

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS 
		${dialect_libs} 
		${conversion_libs} 
        MLIROptLib 
		MLIRQuantum 
		MLIRTargetLLVMIR
        MLIRExecutionEngine
        LLVMLinker
		)

add_llvm_executable(qmir compiler.cpp MLIRGen.cpp PairRemovePass.cpp)

target_include_directories(qmir
	PUBLIC . ../Dialect/include ${CMAKE_BINARY_DIR}/Dialect/include
)

target_link_libraries(qmir 
		PRIVATE ${LIBS}
		MLIRAnalysis 
        MLIRCallInterfaces 
        MLIRIR
        MLIRParser 
        MLIRPass
        MLIRSideEffectInterfaces
        MLIRTransforms
		)