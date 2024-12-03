#include "day02.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

bool small_step(int a, int b) {
  return (std::abs(a - b) >= 1) && (std::abs(a - b) <= 3);
}

bool small_steps(const std::vector<int> &level) {
  return std::ranges::all_of(
      std::views::zip(level, level | std::views::drop(1)),
      [](std::pair<int, int> p) { return small_step(p.first, p.second); });
}

bool asc_or_desc(const std::vector<int> &level) {
  std::vector<int> level_reverse{};
  std::ranges::reverse_copy(level, std::back_inserter(level_reverse));
  return std::ranges::is_sorted(level) || std::ranges::is_sorted(level_reverse);
}

bool is_safe(const std::vector<int> &level) {
  return small_steps(level) and asc_or_desc(level);
}

int part1(const std::string &filename) {
  int count = 0;
  for (const auto &line : readLines(PARENT_DIR "/" + filename)) {
    if (is_safe(ints(line))) {
      count++;
    }
  }
  return count;
}

int part2(const std::string &filename) { return 0; }
