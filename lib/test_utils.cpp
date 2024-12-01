#include "utils.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(IntsTest, ConvertInts) {
  std::string ints_str = "23 45 -12";

  EXPECT_THAT(ints(ints_str), testing::ElementsAre(23, 45, -12));
}
