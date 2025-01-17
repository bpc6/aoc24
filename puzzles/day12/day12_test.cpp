#include "day12.h"
#include <gtest/gtest.h>

TEST(Day12Test, Part1Test1) { EXPECT_EQ(part1("test1.txt"), 140); }
TEST(Day12Test, Part1Test2) { EXPECT_EQ(part1("test2.txt"), 772); }
TEST(Day12Test, Part1) { EXPECT_EQ(part1("test.txt"), 1930); }
TEST(Day12Test, Part2Test1) { EXPECT_EQ(part2("test1.txt"), 80); }
TEST(Day12Test, Part2Test2) { EXPECT_EQ(part2("test2.txt"), 436); }
TEST(Day12Test, Part2Test3) { EXPECT_EQ(part2("test3.txt"), 64); }
TEST(Day12Test, Part2) { EXPECT_EQ(part2("test.txt"), 1206); }
