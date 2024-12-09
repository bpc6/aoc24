#include "day07.h"
#include "parsing.h"

bool solvable(long solution, const std::vector<int> &numbers,
              const std::vector<std::function<long(long, long)>> &operators) {
  auto num_operators = numbers.size() - 1;
  for (const auto &op_combo : op_combos(num_operators, operators)) {
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
    if (solvable(soln, nums, {std::multiplies<>(), std::plus<>()})) {
      total += soln;
    }
  }
  return total;
}

long concat(long a, long b) {
  return stol(std::to_string(a) + std::to_string(b));
}

long part2(const std::string &filename) {
  auto lines = readLines(PARENT_DIR "/" + filename);
  long total = 0;
  for (const auto &line : lines) {
    auto soln = stol(split(line, ':')[0]);
    auto nums = ints(split(line, ':')[1]);
    if (solvable(soln, nums, {std::multiplies<>(), std::plus<>(), concat})) {
      total += soln;
    }
  }
  return total;
}
