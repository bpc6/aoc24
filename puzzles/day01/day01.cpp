#include "day01.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::vector<int> get_col(const std::string &filepath, int colnum) {
  auto lines = readLines(filepath);
  std::vector<int> result;
  result.reserve(lines.size());
  for (const auto &line : lines) {
    result.push_back(ints(line)[colnum]);
  }
  return result;
}

int part1(const std::string &filename) {
  auto col0 = get_col(PARENT_DIR "/" + filename, 0);
  auto col1 = get_col(PARENT_DIR "/" + filename, 1);

  std::sort(col0.begin(), col0.end());
  std::sort(col1.begin(), col1.end());

  int total_dist = 0;
  for (auto [a, b] : std::ranges::views::zip(col0, col1)) {
    total_dist += std::abs(a - b);
  }
  return total_dist;
}

int part2(const std::string &filename) {
  auto col0 = get_col(PARENT_DIR "/" + filename, 0);
  auto col1 = get_col(PARENT_DIR "/" + filename, 1);

  auto score = std::accumulate(
      col0.begin(), col0.end(), 0, [&col1](long sum, auto lval) {
        return sum + lval * std::ranges::count(col1, lval);
      });

  return score;
}
