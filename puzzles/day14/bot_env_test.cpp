#include "bot_env.h"
#include <gtest/gtest.h>

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
