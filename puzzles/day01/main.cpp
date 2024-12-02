#include "parsing.h"
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>

std::vector<int> get_col(const std::string &filepath, int colnum) {
  auto lines = readLines(filepath);
  std::vector<int> result;
  result.reserve(lines.size());
  for (const auto &line : lines) {
    result.push_back(ints(line)[colnum]);
  }
  return result;
}

int main() {
  auto col0 = get_col(PARENT_DIR "/input.txt", 0);
  auto col1 = get_col(PARENT_DIR "/input.txt", 1);

  std::sort(col0.begin(), col0.end());
  std::sort(col1.begin(), col1.end());

  int total_dist = 0;
  for (auto [a, b] : std::ranges::views::zip(col0, col1)) {
    total_dist += std::abs(a - b);
  }

  std::cout << total_dist << std::endl;
  return EXIT_SUCCESS;
}
