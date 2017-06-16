cmake_minimum_required(VERSION 3.6)
project(float_test_tests)

include_directories(unit)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../libs/gtest ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
add_subdirectory(unit)
