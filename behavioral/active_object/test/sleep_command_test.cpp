// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <command.h>
#include <sleep_command.h>
#include <active_object_engine.h>
#include <chrono>

namespace active_object_test {
using active_object::Command;
using active_object::WakeUpCommand;
using active_object::SleepCommand;
using active_object::ActiveObjectEngine;
class SleepCommandTest : public ::testing::Test {
};

TEST_F(SleepCommandTest, TestSleepActiveObjectEngine) {

  
  ActiveObjectEngine e {};
}

TEST_F(SleepCommandTest, WakeUpCommand) {
  WakeUpCommand c {};
  EXPECT_FALSE(c.IsExecuted());
  c.Execute();
  EXPECT_TRUE(c.IsExecuted());
}

TEST_F(SleepCommandTest, SleepCommand) {
  constexpr int kWaitTenMilliSec = 10;
  ActiveObjectEngine e {};
  WakeUpCommand wakeup {};
  SleepCommand c {&e, &wakeup, kWaitTenMilliSec};
  e.AddCommand(&c);

  auto start = std::chrono::system_clock::now();
  e.Run();
  auto end = std::chrono::system_clock::now();
  int elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
  EXPECT_GE(elapsed, kWaitTenMilliSec);
  EXPECT_LE(elapsed, kWaitTenMilliSec);
}

}  // namespace active_object_test