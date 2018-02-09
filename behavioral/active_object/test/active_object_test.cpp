// Copyright <2018> Tomoyuki-Nakabayashi
// This software is released under the MIT License, see LICENSE.

#include <gtest/gtest.h>
#include <command.h>

namespace active_object_test {
class ActiveObjectTest : public ::testing::Test {
};

TEST_F(ActiveObjectTest, FirstTest) {
  EXPECT_TRUE(true);
}
}  // namespace active_object_test