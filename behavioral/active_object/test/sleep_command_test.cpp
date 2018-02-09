// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>

namespace active_object_test {
class SleepCommandTest : public ::testing::Test {
};

TEST_F(SleepCommandTest, FirstTest) {
  bool commandExecuted = false;
  class WakeUpCommand : public Command {
   public:
      void execute() override { commandExecuted = true; }
  };
  EXPECT_TRUE(true);
}
}  // namespace active_object_test