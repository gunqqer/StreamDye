cmake_minimum_required(VERSION 3.10)

project(StreamDye VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)


set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -pedantic -Werror -D_GLIBCXX_DEBUG -lasn -fsanitize=undefined -fsanitize=address")
set(CMAKE_LINKER_FLAGS_DEBUG "-fsanitize=address")

enable_testing()
add_executable(StreamDyeTest "./tests/test.cpp") #Requires <concepts>, gcc 10, clang 10
add_test(NAME mainTest COMMAND StreamDyeTest)

add_executable(StreamDyeUserPlay "./tests/commandline.cpp")

