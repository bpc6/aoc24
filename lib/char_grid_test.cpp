#include "char_grid.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class GridTest : public testing::Test {
protected:
  CharGrid grid_{{{'a', 'b', 'c'}, {'d', 'e', 'a'}}};
};

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
