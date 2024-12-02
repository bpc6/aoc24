#include "aocmath.h"
#include <gtest/gtest.h>

TEST(LCDTest, Basic) {
  EXPECT_EQ(lcd(2, 3), 6);
}

TEST(GCDTest, Basic) {
  EXPECT_EQ(gcd(12, 18), 6);
}