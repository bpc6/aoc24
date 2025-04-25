#include "day11.h"
#include "parsing.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <ranges>

unsigned long count_digits(unsigned long n) {
  if (n == 0)
    return 1;
  return std::to_string(n).length();
}

std::pair<unsigned long, unsigned long> split_digits(unsigned long n) {
  const auto s = std::to_string(n);
  return {std::stol(s.substr(0, s.length() / 2)),
          std::stol(s.substr(s.length() / 2, s.length()))};
}

size_t size_after_updates(size_t curr, int count,
                          std::map<size_t, std::map<size_t, size_t>> &cache) {
  if (cache.contains(curr) && cache[curr].contains(count)) {
    return cache[curr][count];
  }

  size_t result;

  if (count == 0)
    result = 1;
  else if (curr == 0)
    result = size_after_updates(1, count - 1, cache);
  else if (count_digits(curr) % 2 == 0) {
    const auto [left, right] = split_digits(curr);
    result = size_after_updates(left, count - 1, cache) +
             size_after_updates(right, count - 1, cache);
  } else
    result = size_after_updates(curr * 2024, count - 1, cache);

  cache[curr][count] = result;
  return result;
}

size_t part1(const std::string &filename) {
  std::map<size_t, std::map<size_t, size_t>> cache;

  return std::ranges::fold_left(ints(readFile(PARENT_DIR "/" + filename)) |
                                    std::views::transform([&cache](int a) {
                                      return size_after_updates(a, 25, cache);
                                    }),
                                0, std::plus<>{});
}

size_t part2(const std::string &filename) {
  std::map<size_t, std::map<size_t, size_t>> cache;

  return std::ranges::fold_left(ints(readFile(PARENT_DIR "/" + filename)) |
                                    std::views::transform([&cache](int a) {
                                      return size_after_updates(a, 75, cache);
                                    }),
                                0, std::plus<>{});
}
