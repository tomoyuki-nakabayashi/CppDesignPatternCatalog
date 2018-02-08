cmake_minimum_required(VERSION 2.8)
add_executable(active-object active_object/active_object.cpp)
target_link_libraries(active-object gtest_main)