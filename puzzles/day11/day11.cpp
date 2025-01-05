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

size_t size_after_updates(size_t curr, int count) {
  if (count == 0)
    return 1;
  if (curr == 0)
    return size_after_updates(1, count - 1);
  if (count_digits(curr) % 2 == 0) {
    const auto [left, right] = split_digits(curr);
    return size_after_updates(left, count - 1) +
           size_after_updates(right, count - 1);
  }
  return size_after_updates(curr * 2024, count - 1);
}

size_t size_after_updates_mem(size_t curr, int count) {
  return size_after_updates(curr, count);
}

size_t part1(const std::string &filename) {
  return std::ranges::fold_left(ints(readFile(PARENT_DIR "/" + filename)) |
                                    std::views::transform([](int a) {
                                      return size_after_updates_mem(a, 25);
                                    }),
                                0, std::plus<>{});
}

size_t part2(const std::string &filename) {
  return std::ranges::fold_left(ints(readFile(PARENT_DIR "/" + filename)) |
                                    std::views::transform([](int a) {
                                      return size_after_updates_mem(a, 75);
                                    }),
                                0, std::plus<>{});
}
