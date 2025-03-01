#include "day14.h"
#include <gtest/gtest.h>

TEST(Day14Test, Part1) { EXPECT_EQ(part1("test.txt", 11, 7), 0); }
TEST(Day14Test, Part2) { EXPECT_EQ(part2("test.txt", 11, 7), 0); }

TEST(BotEnv, StepsOnce) { BotEnv env{11, 7, {2, 4}, {2, -3}}; }
