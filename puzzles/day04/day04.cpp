#include "day04.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::vector<std::pair<int, int>> find_coords(const char_mat &grid, char c) {
  std::vector<std::pair<int, int>> ret;
  for (auto const [y, row] : std::views::enumerate(grid)) {
    for (auto const [x, val] : std::views::enumerate(row)) {
      if (val == c) {
        ret.push_back({y, x});
      }
    }
  }
  return ret;
}

int count_xmas(const char_mat &grid) {
  //  for (auto x_pos : find_xs(grid)) {
  //    for (auto m_pos : find_near(grid, x_pos) {
  //      direction = m_pos - x_pos;
  //      if (find_as(grid, m_pos, direction)) {
  //        count++;
  //      }
  //    }
  //  }

  return 0;
}

long part1(const std::string &filename) {
  return count_xmas(readCharMatrix(PARENT_DIR "/" + filename));
}

long part2(const std::string &filename) { return 0; }
