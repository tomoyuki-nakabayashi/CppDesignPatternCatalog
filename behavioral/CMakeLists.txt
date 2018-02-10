cmake_minimum_required(VERSION 2.8)
include_directories(active_object/src)
add_executable(active-object
  active_object/src/active_object_engine.cpp
  active_object/src/sleep_command.cpp
  active_object/test/active_object_test.cpp
  active_object/test/sleep_command_test.cpp)
target_link_libraries(active-object gtest_main)