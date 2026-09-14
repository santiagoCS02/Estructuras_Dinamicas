cmake_minimum_required(VERSION 3.10)
project(DynamicStack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(StackApp src/main.cpp)
