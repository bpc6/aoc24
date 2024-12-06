#include "day05.h"
#include "parsing.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ReadRules, Basic) {
  std::vector<std::string> lines{"23|45", "89|12", "23|67", "", "34,13,34"};
  auto rules_map = read_map(lines);
  EXPECT_EQ(rules_map.size(), 2);
  EXPECT_THAT(rules_map[23], testing::ElementsAre(45, 67));
  EXPECT_THAT(rules_map[89], testing::ElementsAre(12));
}

TEST(ReadPageUpdates, Basic) {
  std::vector<std::string> lines{"23|45", "89|12", "", "34,13,36"};
  std::vector<std::vector<int>> expected{{34, 13, 36}};
  EXPECT_THAT(read_page_updates(lines), testing::ElementsAreArray(expected));
}

TEST(CorrectOrder, Basic) {
  auto rules = read_map(readLines(PARENT_DIR "/test.txt"));
  EXPECT_TRUE(correct_order({75, 47, 61, 53, 29}, rules));
  EXPECT_TRUE(correct_order({97, 61, 53, 29, 13}, rules));
  EXPECT_TRUE(correct_order({75, 29, 13}, rules));
  EXPECT_FALSE(correct_order({75, 97, 47, 61, 53}, rules));
  EXPECT_FALSE(correct_order({61, 13, 29}, rules));
  EXPECT_FALSE(correct_order({97, 13, 75, 29, 47}, rules));
}

TEST(Day05Test, Part1) { EXPECT_EQ(part1("test.txt"), 143); }
TEST(Day05Test, Part2) { EXPECT_EQ(part2("test.txt"), 123); }
