#include "day04.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CharGridFindCoords, FindAs) {
  CharGrid grid{{{'a', 'b', 'c'}, {'d', 'e', 'a'}}};
  auto a_coords = grid.find_coords('a');

  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_EQ(a_coords[0], Eigen::Vector2i(0, 0));
  EXPECT_EQ(a_coords[1], Eigen::Vector2i(2, 1));
}

TEST(CharGridFindNear, AsNearB) {
  CharGrid grid{{{'a', 'b', 'c'}, {'d', 'e', 'a'}}};
  auto a_coords = grid.find_near('a', {1, 0});
  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_THAT(a_coords[0], Eigen::Vector2i(0, 0));
  EXPECT_THAT(a_coords[1], Eigen::Vector2i(2, 1));
}

TEST(CharGridFindNear, AsNearD) {
  CharGrid grid{{{'a', 'b', 'c'}, {'d', 'e', 'a'}}};
  auto a_coords = grid.find_near('a', {0, 1});
  EXPECT_EQ(a_coords.size(), 1);
  EXPECT_THAT(a_coords[0], Eigen::Vector2i(0, 0));
}

TEST(Day04Test, Part1) { EXPECT_EQ(part1("test.txt"), 18); }
TEST(Day04Test, Part2) { EXPECT_EQ(part2("test.txt"), 9); }
