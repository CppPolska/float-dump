include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB_RECURSE SOURCE_FILES *.cpp)
add_executable(float_test_tests ${SOURCE_FILES})

target_link_libraries(float_test_tests gtest gtest_main)
target_link_libraries(float_test_tests float_test_library)