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
    total += cost_of_prize(a, b, p + Vec{10000000000000, 10000000000000});
  }
  return total;
}

bool near_whole(float f) {
  constexpr float epsilon = 1e-3f;
  return std::abs(f - std::round(f)) <= epsilon;
}

size_t cost_of_prize(const Vec &dir_a, const Vec &dir_b, const Vec &prize) {
  Eigen::Matrix2f mat;
  mat << dir_a.cast<float>(), dir_b.cast<float>();

  Eigen::Matrix2f inv;
  bool invertible;
  mat.computeInverseWithCheck(inv, invertible);
  if (not invertible)
    return 0;
  auto soln = (inv * prize.cast<float>()).eval();
  if (near_whole(soln.x()) and near_whole(soln.y()))
    return std::round(soln.x()) * 3 + std::round(soln.y());
  return 0;
}
