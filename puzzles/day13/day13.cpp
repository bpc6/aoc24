#include "day13.h"
#include "parsing.h"
#include <cctype>
#include <ranges>

size_t numeric_only(const std::string &s) {
  auto nums = s | std::views::filter([](char c) { return std::isdigit(c); });
  return std::stol(std::string{nums.begin(), nums.end()});
}

Vec parse_line(std::string line) {
  return {numeric_only(split(line, ',')[0]), numeric_only(split(line, ',')[1])};
}

std::tuple<Vec, Vec, Vec> parse_input(std::string paragraph) {
  const auto lines = split(paragraph, '\n');
  return {parse_line(lines[0]), parse_line(lines[1]), parse_line(lines[2])};
}

size_t day13_solution(const std::string &filename, Vec add_to_prize = {0, 0}) {
  size_t total = 0;
  auto txt = readFile(PARENT_DIR "/" + filename);
  for (const auto grp : split(txt, "\n\n")) {
    auto [a, b, prize] = parse_input(grp);
    total += cost_of_prize(a, b, prize + add_to_prize);
  }
  return total;
}

size_t part1(const std::string &filename) { return day13_solution(filename); }

size_t part2(const std::string &filename) {
  return day13_solution(filename, Vec{10000000000000, 10000000000000});
}

bool near_whole(double d) {
  constexpr double epsilon = 1e-3f;
  return std::abs(d - std::round(d)) <= epsilon;
}

size_t cost(const Eigen::Vector2d &soln) {
  return std::round(soln.x()) * 3 + std::round(soln.y());
}

size_t cost_of_prize(const Vec &dir_a, const Vec &dir_b, const Vec &prize) {
  Eigen::Matrix2d mat;
  mat << dir_a.cast<double>(), dir_b.cast<double>();

  Eigen::Matrix2d inv;
  bool invertible;
  mat.computeInverseWithCheck(inv, invertible);
  if (not invertible)
    return 0;
  auto soln = inv * prize.cast<double>();
  if (near_whole(soln.x()) and near_whole(soln.y()))
    return cost(soln);
  return 0;
}
