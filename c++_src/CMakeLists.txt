cmake_minimum_required(VERSION 3.13)

project(BEETS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
#find_package(Python3 COMPONENTS Intrepreter Development)

add_executable(BEETS main.cpp testRedirection.cpp testRedirection.h)

target_compile_options(BEETS PRIVATE -Wall -Werror)