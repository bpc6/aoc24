#include "day13.h"
#include "parsing.h"
#include <ranges>

size_t part1(const std::string &filename) { return 0; }

size_t part2(const std::string &filename) { return 0; }

size_t cost_of_prize(const Eigen::Vector2i &dir_a, const Eigen::Vector2i &dir_b,
                     const Eigen::Vector2i &prize) {
  Eigen::Vector2i curr = {0, 0};
  int cost = 0;
  for (int a_depth : std::views::iota(0, 100)) {
    Eigen::Vector2i tmp = curr;
    int tmp_cost = cost;
    for (int b_depth : std::views::iota(0, 100)) {
      if (tmp == prize)
        return tmp_cost;
      if (tmp.x() > prize.x() or tmp.y() > prize.y())
        break;
      tmp += dir_b;
      tmp_cost += 1;
    }
    curr += dir_a;
    cost += 3;
  }
  return 0;
}
