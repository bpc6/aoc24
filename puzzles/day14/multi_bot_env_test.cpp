#include "multi_bot_env.h"
#include <gtest/gtest.h>

TEST(MultiBotEnv, SafteyFactor) {
  MultiBotEnv env{11,
                  7,
                  {{6, 0},
                   {6, 0},
                   {9, 0},
                   {0, 2},
                   {1, 3},
                   {2, 3},
                   {5, 4},
                   {3, 5},
                   {4, 5},
                   {4, 5},
                   {6, 1},
                   {6, 6}}};
  EXPECT_EQ(env.safety_factor(), 12);
}

TEST(MultiBotEnv, AllUniqueTrueForAllUnique) {
  MultiBotEnv env{11, 7, {{6, 0}, {9, 0}, {6, 1}, {6, 6}}};
  EXPECT_TRUE(env.all_unique());
}
TEST(MultiBotEnv, AllUniqueFalseWhenDuplicate) {
  MultiBotEnv env{11, 7, {{6, 0}, {9, 0}, {6, 1}, {9, 0}, {6, 6}}};
  EXPECT_FALSE(env.all_unique());
}
