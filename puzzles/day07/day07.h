#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <algorithm>
#include <functional>
#include <ranges>
#include <string>
#include <vector>

template <typename T>
std::vector<std::vector<T>> op_combos(size_t slots,
                                      const std::vector<T> &operators) {
  std::vector<std::vector<T>> result{{}};

  for (auto i = 0; i < slots; ++i) {
    auto tmp(result);
    std::ranges::copy(tmp, std::back_inserter(result));
    //    std::ranges::copy(tmp, std::back_inserter(result));
    for (auto [combo_idx, combo] : std::views::enumerate(result)) {
      auto op_idx = combo_idx < result.size() / 2 ? 0 : 1;
      auto op_idx_2 = combo_idx % operators.size();
      combo.push_back(operators[op_idx]);
    }
  }

  return result;
}

bool solvable(long solution, const std::vector<int> &numbers,
              const std::vector<std::function<long(long, long)>> &operators);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
