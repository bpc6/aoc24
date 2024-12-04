#include "day02.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

#include <iostream>

bool small_step(int a, int b) {
  return (std::abs(a - b) >= 1) && (std::abs(a - b) <= 3);
}

template <std::ranges::range R> bool small_steps(const R &level) {
  return std::ranges::all_of(
      std::views::zip(level, level | std::views::drop(1)),
      [](std::pair<int, int> p) { return small_step(p.first, p.second); });
}

template <std::ranges::range R> bool asc_or_desc(const R &level) {
  std::vector<int> level_reverse{};
  std::ranges::reverse_copy(level, std::back_inserter(level_reverse));
  return std::ranges::is_sorted(level) || std::ranges::is_sorted(level_reverse);
}

template <std::ranges::range R> bool is_safe(const R &level) {
  return small_steps(level) and asc_or_desc(level);
}

long part1(const std::string &filename) {
  return std::ranges::count_if(
      readLines(PARENT_DIR "/" + filename),
      [](const std::string &line) { return is_safe(ints(line)); });
}

std::vector<int> drop_ith(const std::vector<int> &v, std::size_t i) {
  std::vector<int> result;
  for (auto idx = 0; idx < i; ++idx) {
    result.push_back(v[idx]);
  }
  for (auto idx = i + 1; idx < v.size(); idx++) {
    result.push_back(v[idx]);
  }
  return result;
}

bool is_safe_after_removal(const std::vector<int> &level) {
  return std::ranges::any_of(
      std::views::iota(0u, level.size()),
      [&level](int idx) { return is_safe(drop_ith(level, idx)); });
}

long part2(const std::string &filename) {
  return std::ranges::count_if(readLines(PARENT_DIR "/" + filename),
                               [](const std::string &line) {
                                 return is_safe_after_removal(ints(line));
                               });
}
