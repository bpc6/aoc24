#include "day08.h"
#include <gtest/gtest.h>

TEST(Day08Test, Part1Basic) { EXPECT_EQ(part1("test_basic.txt"), 4); }
TEST(Day08Test, Part1) { EXPECT_EQ(part1("test.txt"), 14); }
TEST(Day08Test, Part2) { EXPECT_EQ(part2("test.txt"), 34); }
