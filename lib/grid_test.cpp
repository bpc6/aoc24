#include "grid.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <ranges>

class GridTest : public testing::Test {
protected:
  Grid<char> grid_{{{'a', 'b', 'c'}, {'d', 'e', 'a'}}};
};

TEST_F(GridTest, BracketAccess) {
  auto c = grid_[{1, 1}];
  EXPECT_EQ(c, 'e');
  c = 'z';
  auto new_c = grid_[{1, 1}];
  EXPECT_EQ(c, 'z');
  EXPECT_EQ(new_c, 'e');
}

TEST_F(GridTest, BracketModify) {
  auto c = grid_[{1, 1}];
  EXPECT_EQ(c, 'e');
  grid_[{1, 1}] = 'z';
  auto new_c = grid_[{1, 1}];
  EXPECT_EQ(c, 'e');
  EXPECT_EQ(new_c, 'z');
}

TEST_F(GridTest, HasCoord) {
  EXPECT_TRUE(grid_.has_coord({2, 1}));
  EXPECT_FALSE(grid_.has_coord({1, 2}));
}

TEST_F(GridTest, FindCoords) {
  auto a_coords = grid_.find_coords('a');

  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_EQ(a_coords[0], Eigen::Vector2i(0, 0));
  EXPECT_EQ(a_coords[1], Eigen::Vector2i(2, 1));
}

TEST_F(GridTest, AsNearB) {
  auto a_coords = grid_.find_near('a', {1, 0});
  EXPECT_EQ(a_coords.size(), 2);
  EXPECT_THAT(a_coords[0], Eigen::Vector2i(0, 0));
  EXPECT_THAT(a_coords[1], Eigen::Vector2i(2, 1));
}

TEST_F(GridTest, AsNearD) {
  auto a_coords = grid_.find_near('a', {0, 1});
  EXPECT_EQ(a_coords.size(), 1);
  EXPECT_THAT(a_coords[0], Eigen::Vector2i(0, 0));
}

TEST_F(GridTest, HeightAndWidth) {
  EXPECT_EQ(grid_.height(), 2);
  EXPECT_EQ(grid_.width(), 3);
}
