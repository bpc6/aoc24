#include "day11.h"
#include <gtest/gtest.h>

TEST(Day11Test, Part1) { EXPECT_EQ(part1("test.txt"), 55312); }

TEST(SplitDigits, Splits456789) {
  const auto [left, right] = split_digits(456789);
  EXPECT_EQ(left, 456);
  EXPECT_EQ(right, 789);
}
