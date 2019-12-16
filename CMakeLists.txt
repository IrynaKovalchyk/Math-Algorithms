cmake_minimum_required(VERSION 3.8)
project(array)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Array.h Exception.h Exception.cpp)
add_executable(array ${SOURCE_FILES})