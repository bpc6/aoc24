#include "day04.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(FindInGrid, Basic) {
    auto finder = find_in_grid({{'a', 'b', 'c'}, {'d', 'e', 'a'}});
    std::pair<size_t, size_t> pos;

    EXPECT_TRUE(finder(pos, 'a'));
    EXPECT_THAT(pos, testing::Pair(0, 0));

    EXPECT_TRUE(finder(pos, 'a'));
    EXPECT_THAT(pos, testing::Pair(1, 2));

    EXPECT_FALSE(finder(pos, 'a'));
}

TEST(Day04Test, Part1) { EXPECT_EQ(part1("test.txt"), 18); }
TEST(Day04Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
