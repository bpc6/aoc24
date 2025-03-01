#include "day14.h"
#include <gtest/gtest.h>

TEST(Day14Test, Part1) { EXPECT_EQ(part1("test.txt", 11, 7), 0); }
TEST(Day14Test, Part2) { EXPECT_EQ(part2("test.txt", 11, 7), 0); }

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

TEST(BotEnvFactory, GeneratesEnvWithCorrectPos) {
  auto env = bot_env_factory(11, 7, "p=0,4 v=3,-3\n");
  EXPECT_EQ(env.pos(), Vec(0, 4));
}

TEST(BotEnv, StepsOnce) {
  BotEnv env{11, 7, {2, 4}, {2, -3}};
  env.step();

  EXPECT_EQ(env.pos(), Vec(4, 1));
}

TEST(BotEnv, StepsOnceWraps) {
  BotEnv env{11, 7, {4, 1}, {2, -3}};
  env.step();

  EXPECT_EQ(env.pos(), Vec(6, 5));
}

TEST(BotEnv, Steps5x) {
  BotEnv env{11, 7, {2, 4}, {2, -3}};
  for (int i = 0; i < 5; i++)
    env.step();

  EXPECT_EQ(env.pos(), Vec(1, 3));
}
