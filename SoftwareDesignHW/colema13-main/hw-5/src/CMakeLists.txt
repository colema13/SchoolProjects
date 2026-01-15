project(calculator)

add_library(calculator)

target_sources(
    calculator
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Calculator.cpp
)

target_include_directories(
    calculator
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)
