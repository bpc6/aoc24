#include "day04.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::optional<std::pair<size_t, size_t>> find_in_grid::operator()() {
  for (; curr.first < grid.size(); ++curr.first) {
    while (curr.second < grid[curr.first].size()) {
      if (grid[curr.first][curr.second] == c) {
        auto ret = curr;
        curr.second++;
        return ret;
      }
      curr.second++;
    }
    curr.second = 0;
  }
  return {};
}

int count_xmas(const char_mat &grid) {
  while (auto x_pos = find_in_grid(grid, 'X')()) {
    //        if (find_m(grid, x_pos, m_pos)) {
    //            direction = m_pos - x_pos;
    //            if (find_as(grid, m_pos, direction)) {
    //                count++;
    //            }
    //        }
  }

  return 0;
}

long part1(const std::string &filename) {
  return count_xmas(readCharMatrix(PARENT_DIR "/" + filename));
}

long part2(const std::string &filename) { return 0; }
