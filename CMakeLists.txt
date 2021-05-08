cmake_minimum_required(VERSION 3.10)

project(StreamDye VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB test "./tests/test.cpp")

add_compile_options(-Wall -Wextra -pedantic -Werror)

enable_testing()
add_executable(StreamDyeTest ${test}) #Requires <concepts>, gcc 10, clang 10
add_test(NAME mainTest COMMAND StreamDyeTest)

