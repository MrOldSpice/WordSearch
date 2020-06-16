# cmake_minimum_required(VERSION <specify CMake version here>)
project(WordSearch)

set(CMAKE_CXX_STANDARD 14)

add_executable(WordSearch main.cpp wordSearch_Source.cpp wordSearch_Head.h search.h search.cpp)
