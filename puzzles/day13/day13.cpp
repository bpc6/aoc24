#include "day13.h"
#include "parsing.h"
#include <cctype>
#include <ranges>

using Vec = Eigen::Vector2i;

int numeric_only(const std::string &s) {
  auto nums = s | std::views::filter([](char c) { return std::isdigit(c); });
  return std::stoi(std::string{nums.begin(), nums.end()});
}

Vec parse_line(std::string line) {
  return {numeric_only(split(line, ',')[0]), numeric_only(split(line, ',')[1])};
}

std::tuple<Vec, Vec, Vec> parse_input(std::string paragraph) {
  const auto lines = split(paragraph, '\n');
  return {parse_line(lines[0]), parse_line(lines[1]), parse_line(lines[2])};
}

size_t part1(const std::string &filename) {
  size_t total = 0;
  auto txt = readFile(PARENT_DIR "/" + filename);
  for (const auto grp : split(txt, "\n\n")) {
    auto [a, b, p] = parse_input(grp);
    total += cost_of_prize(a, b, p);
  }
  return total;
}

size_t part2(const std::string &filename) {
  size_t total = 0;
  auto txt = readFile(PARENT_DIR "/" + filename);
  for (const auto grp : split(txt, "\n\n")) {
    auto [a, b, p] = parse_input(grp);
    total += cost_of_prize(a, b, p + Vec{0, 0});
  }
  return total;
}

size_t cost_of_prize(const Vec &dir_a, const Vec &dir_b, const Vec &prize) {
  Vec curr = {0, 0};
  int cost = 0;
  for (int a_depth : std::views::iota(0, 100)) {
    Vec tmp = curr;
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
