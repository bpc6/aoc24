#include "day13.h"
#include "parsing.h"
#include <ranges>

size_t part1(const std::string &filename) { return 0; }

size_t part2(const std::string &filename) { return 0; }

size_t cost_of_prize(const Eigen::Vector2i &dir_a, const Eigen::Vector2i &dir_b,
                     const Eigen::Vector2i &prize, const int a_depth,
                     const int b_depth) {
  if (a_depth == 100 && b_depth == 100)
    return 0;

  return 0;
}
