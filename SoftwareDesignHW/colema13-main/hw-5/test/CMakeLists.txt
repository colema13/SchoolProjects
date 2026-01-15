find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(calculator_tests)

target_sources(calculator_tests
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/CalculatorTests.cpp
)

target_include_directories(calculator_tests
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(calculator_tests
    PRIVATE
    calculator
    ${Boost_LIBRARIES}
)