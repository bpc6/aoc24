#include "day15.h"
#include <gtest/gtest.h>

TEST(Day15Test, Part1) { EXPECT_EQ(part1("test.txt"), 0); }
TEST(Day15Test, Part1Big) { EXPECT_EQ(part1("test_big.txt"), 0); }
TEST(Day15Test, Part2) { EXPECT_EQ(part1("test.txt"), 0); }

TEST(WarehouseBotEnv, Creates) {
  WarehouseBotEnv env({3, 3}, {{0, 0}, {1, 0}}, {{0, 1}}, {2, 2});
  std::string expected = "##.\nO..\n..@\n";
  EXPECT_EQ(env.to_string(), expected);
}
