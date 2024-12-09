#include "day07.h"
#include "parsing.h"
#include <algorithm>
#include <ranges>

std::vector<std::vector<std::function<long(long, long)>>>
op_combos(size_t slots) {
  std::vector<std::function<long(long, long)>> operators{std::multiplies<>(),
                                                         std::plus<>()};
  std::vector<std::vector<std::function<long(long, long)>>> result{{}};

  for (auto i = 0; i < slots; ++i) {
    auto tmp(result);
    std::ranges::copy(tmp, std::back_inserter(result));
    for (auto [combo_idx, combo] : std::views::enumerate(result)) {
      auto op_idx = combo_idx < result.size() / 2 ? 0 : 1;
      combo.push_back(operators[op_idx]);
    }
  }

  return result;
}

bool solvable(long solution, const std::vector<int> &numbers) {
  auto num_operators = numbers.size() - 1;
  for (const auto &op_combo : op_combos(num_operators)) {
    auto val = op_combo[0](numbers[0], numbers[1]);
    for (size_t i = 1; i < op_combo.size(); ++i) {
      val = op_combo[i](val, numbers[i + 1]);
    }
    if (val == solution)
      return true;
  }
  return false;
}

long part1(const std::string &filename) {
  auto lines = readLines(PARENT_DIR "/" + filename);
  long total = 0;
  for (const auto &line : lines) {
    auto soln = stol(split(line, ':')[0]);
    auto nums = ints(split(line, ':')[1]);
    if (solvable(soln, nums)) {
      total += soln;
    }
  }
  return total;
}

long part2(const std::string &filename) { return 0; }
