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

add_library(parser_lib ${SOURCES})

add_executable(parser
    src/main.cpp
)

target_link_libraries(parser PRIVATE parser_lib)

# Testing setup with Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.8.1
)

FetchContent_MakeAvailable(Catch2)

file(GLOB_RECURSE TEST_SOURCES
    "tests/*.cpp"
)

add_executable(tests
    ${TEST_SOURCES}
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain parser_lib)

include(CTest)
include(Catch)
catch_discover_tests(tests)
