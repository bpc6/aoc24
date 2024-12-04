#include "day02.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(IsSafeTest, Basic) {
  EXPECT_TRUE(is_safe(std::vector{7, 6, 4, 2, 1}));
  EXPECT_FALSE(is_safe(std::vector{1, 2, 7, 8, 9}));
  EXPECT_FALSE(is_safe(std::vector{9, 7, 6, 2, 1}));
  EXPECT_FALSE(is_safe(std::vector{1, 3, 2, 4, 5}));
  EXPECT_FALSE(is_safe(std::vector{8, 6, 4, 4, 1}));
  EXPECT_TRUE(is_safe(std::vector{1, 3, 6, 7, 9}));
}

TEST(IsSafeAfterRemovalTest, Basic) {
  EXPECT_TRUE(is_safe_after_removal(std::vector{7, 6, 4, 2, 1}));
  EXPECT_FALSE(is_safe_after_removal(std::vector{1, 2, 7, 8, 9}));
  EXPECT_FALSE(is_safe_after_removal(std::vector{9, 7, 6, 2, 1}));
  EXPECT_TRUE(is_safe_after_removal(std::vector{1, 3, 2, 4, 5}));
  EXPECT_TRUE(is_safe_after_removal(std::vector{8, 6, 4, 4, 1}));
  EXPECT_TRUE(is_safe_after_removal(std::vector{1, 3, 6, 7, 9}));
}

TEST(DropIth, Basic) {
  std::vector v{7, 6, 4, 2, 1};
  EXPECT_THAT(drop_ith(v, 2), testing::ElementsAre(7, 6, 2, 1));
}

TEST(Day02Test, Part1) { EXPECT_EQ(part1("test.txt"), 2); }
TEST(Day02Test, Part2) { EXPECT_EQ(part2("test.txt"), 4); }
