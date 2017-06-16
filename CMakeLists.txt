cmake_minimum_required(VERSION 3.6)
project(float_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)