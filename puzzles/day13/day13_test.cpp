#include "day13.h"
#include <gtest/gtest.h>

TEST(Day13Test, Part1) { EXPECT_EQ(part1("test.txt"), 0); }
TEST(Day13Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }

TEST(Day13Test, CostOfPrize0) {
  EXPECT_EQ(cost_of_prize({94, 34}, {22, 67}, {8400, 5400}), 280);
}
