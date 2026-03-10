cmake_minimum_required(VERSION 3.10)
project(parser VERSION 1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/tests
)

file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.c"
    "src/*.cxx"
)

file(GLOB_RECURSE HEADERS
    "include/*.h"
    "include/*.hpp"
    "include/*.hh"
)

add_executable(parser
    ${SOURCES}
)
