cmake_minimum_required(VERSION 3.6)
project(float_test)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_library(float_test_library ${SOURCE_FILES})
add_executable(float_test ${SOURCE_FILES} main.cpp)
