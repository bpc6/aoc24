#include "day14.h"
#include "multi_bot_env.h"
#include "parsing.h"
#include <ranges>

size_t part1(const std::string &filename, int width, int height) {
  MultiBotEnv env{width, height, readLines(PARENT_DIR "/" + filename)};
  for (int i : std::views::iota(0, 100))
    env.step();
  return env.safety_factor();
}

size_t part2(const std::string &filename, int width, int height) {
  MultiBotEnv env{width, height, readLines(PARENT_DIR "/" + filename)};
  size_t count = 0;
  while (!env.all_unique()) {
    env.step();
    count += 1;
  }
  return count;
}
