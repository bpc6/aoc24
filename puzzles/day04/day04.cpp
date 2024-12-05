#include "day04.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::vector<std::pair<int, int>> find_coords(const char_mat &grid, char c) {
  std::vector<std::pair<int, int>> result;
  for (auto const [y, row] : std::views::enumerate(grid)) {
    for (auto const [x, val] : std::views::enumerate(row)) {
      if (val == c) {
        result.push_back({y, x});
      }
    }
  }
  return result;
}

std::vector<std::pair<int, int>> find_near(const char_mat &grid, char c,
                                           std::pair<int, int> target) {
  std::vector<std::pair<int, int>> result;
  const auto [yc, xc] = target;
  for (auto y = std::max(0, yc - 1);
       y < std::min(static_cast<int>(grid.size()), yc + 2); ++y) {
    for (auto x = std::max(0, xc - 1);
         x < std::min(static_cast<int>(grid[y].size()), xc + 2); ++x) {
      if (grid[y][x] == c) {
        result.push_back({y, x});
      }
    }
  }
  return result;
}

int count_xmas(const char_mat &grid) {
  int count = 0;
  for (auto x_pos : find_coords(grid, 'X')) {
    for (auto m_pos : find_near(grid, 'M', x_pos)) {
      auto direction = {m_pos.first - x_pos.first, m_pos.second - x_pos.second};
      //      if (find_as(grid, m_pos, direction)) {
      //        count++;
      //      }
    }
  }

  return count;
}

long part1(const std::string &filename) {
  return count_xmas(readCharMatrix(PARENT_DIR "/" + filename));
}

long part2(const std::string &filename) { return 0; }
