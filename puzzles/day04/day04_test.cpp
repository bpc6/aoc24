#include "day04.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(FindCoords, FindAs) {
  auto a_coords = find_coords({{'a', 'b', 'c'}, {'d', 'e', 'a'}}, 'a');

  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_EQ(a_coords[0], Eigen::Vector2i(0, 0));
  EXPECT_EQ(a_coords[1], Eigen::Vector2i(1, 2));
}

TEST(FindNear, AsNearB) {
  auto a_coords = find_near({{'a', 'b', 'c'}, {'d', 'e', 'a'}}, 'a', {0, 1});
  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_THAT(a_coords[0], testing::Pair(0, 0));
  EXPECT_THAT(a_coords[1], testing::Pair(1, 2));
}

TEST(FindNear, AsNearD) {
  auto a_coords = find_near({{'a', 'b', 'c'}, {'d', 'e', 'a'}}, 'a', {1, 0});
  EXPECT_EQ(a_coords.size(), 1);
  EXPECT_THAT(a_coords[0], testing::Pair(0, 0));
}

TEST(Day04Test, Part1) { EXPECT_EQ(part1("test.txt"), 18); }
TEST(Day04Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
