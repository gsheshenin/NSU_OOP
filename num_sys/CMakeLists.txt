cmake_minimum_required(VERSION 3.27)
project(OOP2024)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

add_subdirectory(googletest)

include_directories(gtests/googletest/include)

add_executable(OOP2024
        maths.cpp
        maths.hpp
        filehandler.hpp
        filehandler.cpp
        bigint.hpp
        bigint.cpp
        tests.cpp)

target_link_libraries(OOP2024 gtest gtest_main)

add_test(NAME test1 COMMAND OOP2024)