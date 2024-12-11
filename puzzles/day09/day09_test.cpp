#include "day09.h"
#include <gtest/gtest.h>

TEST(CompressDisc, TinyExample) {
  EXPECT_EQ(compress_disc("12345"), "022111222");
}
TEST(CompressDisc, Example) {
  EXPECT_EQ(compress_disc("2333133121414131402"),
            "0099811188827773336446555566");
}

TEST(Day09Test, Part1) { EXPECT_EQ(part1("test.txt"), 1928); }
TEST(Day09Test, Part2) { EXPECT_EQ(part2("test.txt"), 0); }
