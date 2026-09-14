cmake_minimum_required(VERSION 3.15)
project(MyStack CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(${CMAKE_SOURCE_DIR}/include)

# Ejecutable principal (aplicacion de consola)
add_executable(MyStack
    src/main.cpp
    src/ConsoleMenu.cpp
)

# Ejecutable de tests (independiente del anterior)
add_executable(MyStackTests
    tests/StackTests.cpp
)

enable_testing()
add_test(NAME StackTests COMMAND MyStackTests)
