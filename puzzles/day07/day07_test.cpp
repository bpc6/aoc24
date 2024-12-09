#include "day07.h"
#include <gtest/gtest.h>

TEST(Solvable, Basic) {
  EXPECT_TRUE(solvable(190, {10, 19}));
  EXPECT_TRUE(solvable(3267, {81, 40, 27}));
  EXPECT_FALSE(solvable(83, {17, 5}));
}

TEST(day07Test, Part1) { EXPECT_EQ(part1("test.txt"), 3749); }
TEST(day07Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
