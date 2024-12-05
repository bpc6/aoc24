#include "day05.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(ReadRules, Basic) {
    std::vector<std::string> lines{"23|45", "89|12", "", "34,13,34"};
    std::vector<std::pair<int, int>> expected{{23, 45}, {89,12}};
    EXPECT_THAT(read_rules(lines), testing::ElementsAreArray(expected));
}

TEST(ReadPageUpdates, Basic) {
    std::vector<std::string> lines{"23|45", "89|12", "", "34,13,36"};
    std::vector<std::vector<int>> expected{{34, 13, 36}};
    EXPECT_THAT(read_page_updates(lines), testing::ElementsAreArray(expected));
}

TEST(Day05Test, Part1) { EXPECT_EQ(part1("test.txt"), 143); }
TEST(Day05Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
