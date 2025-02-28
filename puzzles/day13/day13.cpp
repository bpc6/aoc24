#include "day13.h"
#include "parsing.h"
#include <cctype>
#include <ranges>

int numeric_only(const std::string &s) {
  auto nums = s | std::views::filter([](char c) { return std::isdigit(c); });
  return std::stoi(std::string{nums.begin(), nums.end()});
}

size_t part1(const std::string &filename) {
  size_t total = 0;
  auto txt = readFile(PARENT_DIR "/" + filename);
  for (const auto grp : split(txt, "\n\n")) {
    const auto lines = split(grp, '\n');
    Eigen::Vector2i a = {numeric_only(split(lines[0], ',')[0]),
                         numeric_only(split(lines[0], ',')[1])};
    Eigen::Vector2i b = {numeric_only(split(lines[1], ',')[0]),
                         numeric_only(split(lines[1], ',')[1])};
    Eigen::Vector2i p = {numeric_only(split(lines[2], ',')[0]),
                         numeric_only(split(lines[2], ',')[1])};
    total += cost_of_prize(a, b, p);
  }
  return total;
}

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
