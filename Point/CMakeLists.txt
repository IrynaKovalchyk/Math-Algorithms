cmake_minimum_required(VERSION 3.8)
project(Point)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Point.cpp Point.h HoolaHoop.cpp HoolaHoop.h)
add_executable(Point ${SOURCE_FILES})