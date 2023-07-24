set(LIBRARY_NAME quantum-pass)

file(GLOB SRC *.cpp)

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
    ${dialect_libs}
    ${conversion_libs}
    MLIRQuantum
    MLIROptLib
    MLIRTargetLLVMIR
    MLIRExecutionEngine
    )

add_mlir_library(${LIBRARY_NAME} SHARED ${SRC} LINK_LIBS PUBLIC ${LIBS})

target_include_directories(${LIBRARY_NAME}
    PUBLIC . ../Dialect/include ${CMAKE_BINARY_DIR}/Dialect/include)



