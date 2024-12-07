#include "day06.h"
#include "grid.h"
#include <gtest/gtest.h>

TEST(CountVisited, Basic) { EXPECT_EQ(part1("test_small.txt"), 6); }
TEST(Day01Test, Part1) { EXPECT_EQ(part1("test.txt"), 41); }
TEST(Day01Test, Part2) { EXPECT_EQ(part2("test.txt"), 6); }
