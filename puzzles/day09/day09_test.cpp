#include "day09.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CompressDisc, TinyExample) {
  EXPECT_THAT(compress_disc("12345"),
              testing::ElementsAre(0, 2, 2, 1, 1, 1, 2, 2, 2));
}
TEST(CompressDisc, Example) {
  EXPECT_THAT(compress_disc("2333133121414131402"),
              testing::ElementsAre(0, 0, 9, 9, 8, 1, 1, 1, 8, 8, 8, 2, 7, 7, 7,
                                   3, 3, 3, 6, 4, 4, 6, 5, 5, 5, 5, 6, 6));
}
// TEST(CompressDiscWholeFiles, Example) {
//   EXPECT_THAT(compress_disc_whole_files("2333133121414131402"),
//               testing::ElementsAre(0, 0, 9, 9, 2, 1, 1, 1, 7, 7, 7, 4, 4, 3,
//               3,
//                                    3, 5, 5, 5, 5, 6, 6, 6, 6, 8, 8, 8, 8));
// }

TEST(Day09Test, Part1) { EXPECT_EQ(part1("test.txt"), 1928); }
TEST(Day09Test, Part2) { EXPECT_EQ(part2("test.txt"), 2858); }
