#include "day15.h"
#include <gtest/gtest.h>

TEST(Day15Test, Part1) { EXPECT_EQ(part1("test.txt"), 0); }
TEST(Day15Test, Part1Big) { EXPECT_EQ(part1("test_big.txt"), 0); }
TEST(Day15Test, Part2) { EXPECT_EQ(part1("test.txt"), 0); }

class WarehouseBotEnvTest : public testing::Test {
protected:
  WarehouseBotEnv env{
      {4, 4}, {{0, 0}, {1, 0}, {0, 1}}, {{1, 1}, {2, 1}, {2, 2}}, {2, 0}};
};

TEST_F(WarehouseBotEnvTest, CtorPlacesProperly) {
  std::string expected = "##@.\n#OO.\n..O.\n....\n";
  EXPECT_EQ(env.to_string(), expected);
}

TEST_F(WarehouseBotEnvTest, StepWithNoObstruction) {
  env.step({1, 0});
  EXPECT_EQ(env.get_pos(), Coord(3, 0));
}

TEST_F(WarehouseBotEnvTest, StepIntoWallDoesntMove) {
  env.step({-1, 0});
  EXPECT_EQ(env.get_pos(), Coord(2, 0));
}

TEST_F(WarehouseBotEnvTest, StepIntoCrateMovesCrates) {
  EXPECT_TRUE(env.is_crate({2, 1}));
  EXPECT_TRUE(env.is_crate({2, 2}));
  EXPECT_FALSE(env.is_crate({2, 3}));
  env.step({0, 1});

  EXPECT_EQ(env.get_pos(), Coord(2, 1));
  EXPECT_FALSE(env.is_crate({2, 1}));
  EXPECT_TRUE(env.is_crate({2, 2}));
  EXPECT_TRUE(env.is_crate({2, 3}));
}

TEST_F(WarehouseBotEnvTest, StepIntoBlockedCrateDoesntMove) {
  env.set_pos({3, 1});
  const auto before = env.to_string();
  env.step({-1, 0});
  EXPECT_EQ(env.to_string(), before);
}
