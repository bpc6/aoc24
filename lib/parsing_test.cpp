#include "parsing.h"
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

TEST(IntsTest, HyphenNumeric) {
  std::string ints_str = "-hello";

  EXPECT_THROW(ints(ints_str), std::invalid_argument);
}

TEST(SplitTest, StrSep) {
  std::string comma_sep = "hi, there, friend";

  EXPECT_THAT(split(comma_sep, ", "),
              testing::ElementsAre("hi", "there", "friend"));
}

TEST(JoinTest, WithSep) {
  std::vector<std::string> strings{"hi", "there", "bob"};
  EXPECT_EQ(join(strings, ' '), "hi there bob");
}

TEST(JoinTest, NoSep) {
  std::vector<std::string> strings{"1", "2", "3"};
  EXPECT_EQ(join(strings), "123");
}
