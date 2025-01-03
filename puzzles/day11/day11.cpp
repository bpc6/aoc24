#include "day11.h"
#include "parsing.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <ranges>

unsigned long count_digits(unsigned long n) {
  if (n == 0)
    return 1;
  return static_cast<unsigned long>(std::log10(n)) + 1;
}

std::pair<unsigned long, unsigned long> split_digits(unsigned long n) {
  size_t half_digits = (static_cast<size_t>(std::log10(n)) + 1) / 2;
  auto divisor = static_cast<unsigned long>(std::pow(10, half_digits));
  return {n / divisor, n % divisor};
}

void update(std::vector<size_t> &curr) {
  std::vector<size_t> next;
  for (auto item : curr) {
    if (item == 0) {
      next.push_back(1);
    } else if (count_digits(item) % 2 == 0) {
      const auto [left, right] = split_digits(item);
      next.push_back(left);
      next.push_back(right);
    } else {
      next.push_back(item * 2024);
    }
  }
  curr = std::move(next);
}

size_t size_after_updates(std::vector<size_t> curr, int count) {
  for (int i = 0; i < count; ++i) {
    update(curr);
  }
  return curr.size();
}

size_t part1(const std::string &filename) {
  std::vector<size_t> curr;
  for (const auto &n : ints(readFile(PARENT_DIR "/" + filename))) {
    curr.push_back(n);
  }

  return size_after_updates(curr, 25);
}

size_t part2(const std::string &filename) {
  std::vector<size_t> curr;
  for (const auto &n : ints(readFile(PARENT_DIR "/" + filename))) {
    curr.push_back(n);
  }

  return 0;
}
