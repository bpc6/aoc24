#include "day13.h"
#include <gtest/gtest.h>

TEST(Day13Test, Part1) { EXPECT_EQ(part1("test.txt"), 480); }
TEST(Day13Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }

TEST(Day13Test, NumericOnly) {
  EXPECT_EQ(numeric_only("Button A: X+94, Y+"), 94);
}

TEST(Day13Test, CostOfPrize0) {
  EXPECT_EQ(cost_of_prize({94, 34}, {22, 67}, {8400, 5400}), 280);
  EXPECT_EQ(cost_of_prize({26, 66}, {67, 21}, {12748, 12176}), 0);
  EXPECT_EQ(cost_of_prize({17, 86}, {84, 37}, {7870, 6450}), 200);
}

TEST(Day13Test, CostOfPrize1) {
  EXPECT_EQ(cost_of_prize({94, 34}, {22, 67}, {10000000008400, 10000000005400}),
            0);
  EXPECT_NE(cost_of_prize({26, 66}, {67, 21}, {10000000012748, 10000000012176}),
            0);
  EXPECT_EQ(cost_of_prize({17, 86}, {84, 37}, {10000000007870, 10000000006450}),
            0);
  EXPECT_NE(cost_of_prize({69, 23}, {27, 71}, {10000000018641, 10000000010279}),
            0);
}
