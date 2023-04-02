cmake_minimum_required(VERSION 3.16)
project(BlocksAlgorithm)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./googletest)

add_executable(blocks_algorithm src/main.cpp src/algorithm.cpp src/algorithm.h)

enable_testing()

add_executable(blocks_tests tests/tests.cpp src/algorithm.cpp src/algorithm.h)
target_link_libraries(blocks_tests GTest::gtest_main pthread)