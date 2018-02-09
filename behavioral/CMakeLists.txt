cmake_minimum_required(VERSION 2.8)
add_executable(active-object
  active_object/src/active_object.cpp
  active_object/test/active_object_test.cpp)
target_link_libraries(active-object gtest_main)