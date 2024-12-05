#include "day04.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FindInGrid, Basic) {
  auto finder = find_in_grid({{'a', 'b', 'c'}, {'d', 'e', 'a'}}, 'a');
  auto pos = finder();
  EXPECT_TRUE(pos.has_value());
  EXPECT_THAT(pos.value(), testing::Pair(0, 0));

  pos = finder();
  EXPECT_TRUE(pos.has_value());
  EXPECT_THAT(pos.value(), testing::Pair(1, 2));

  pos = finder();
  EXPECT_FALSE(pos.has_value());
}

TEST(Day04Test, Part1) { EXPECT_EQ(part1("test.txt"), 18); }
TEST(Day04Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
