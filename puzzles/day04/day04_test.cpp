#include "day04.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FindCoords, Basic) {
  auto a_coords = find_coords({{'a', 'b', 'c'}, {'d', 'e', 'a'}}, 'a');

  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_THAT(a_coords[0], testing::Pair(0, 0));
  EXPECT_THAT(a_coords[1], testing::Pair(1, 2));
}

TEST(Day04Test, Part1) { EXPECT_EQ(part1("test.txt"), 18); }
TEST(Day04Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
