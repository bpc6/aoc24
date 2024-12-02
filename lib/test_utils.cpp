#include "utils.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(IntsTest, ConvertInts) {
  std::string ints_str = "23 45 -12";

  EXPECT_THAT(ints(ints_str), testing::ElementsAre(23, 45, -12));
}

TEST(IntsTest, SingleInt) {
  std::string ints_str = "23";

  EXPECT_THAT(ints(ints_str), testing::ElementsAre(23));
}

TEST(IntsTest, InvalidInt) {
  std::string ints_str = "Two 4";

  EXPECT_THROW(ints(ints_str), std::invalid_argument);
}

TEST(IntsTest, WithSep) {
  std::string ints_str = "23,45,-12";

  EXPECT_THAT(ints(ints_str, ','), testing::ElementsAre(23, 45, -12));
}

TEST(IntsTest, TrailingSep) {
  std::string ints_str = "23,45,-12,";

  EXPECT_THAT(ints(ints_str, ','), testing::ElementsAre(23, 45, -12));
}

TEST(SplitTest, StrSep) {
  std::string comma_sep = "hi, there, friend";

  EXPECT_THAT(split(comma_sep, ", "), testing::ElementsAre("hi", "there", "friend"));
}
