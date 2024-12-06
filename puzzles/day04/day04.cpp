#include "day04.h"
#include "parsing.h"
#include <algorithm>
#include <ranges>

std::vector<Eigen::Vector2i> find_coords(const char_mat &grid, char c) {
  std::vector<Eigen::Vector2i> result;
  for (auto const [y, row] : std::views::enumerate(grid)) {
    for (auto const [x, val] : std::views::enumerate(row)) {
      if (val == c) {
        result.push_back({x, y});
      }
    }
  }
  return result;
}

std::vector<Eigen::Vector2i> find_near(const char_mat &grid, char c,
                                       Eigen::Vector2i target) {
  std::vector<Eigen::Vector2i> result;
  for (auto y = std::max(0, target.y() - 1);
       y < std::min(static_cast<int>(grid.size()), target.y() + 2); ++y) {
    for (auto x = std::max(0, target.x() - 1);
         x < std::min(static_cast<int>(grid[y].size()), target.x() + 2); ++x) {
      if (grid[y][x] == c) {
        result.push_back({x, y});
      }
    }
  }
  return result;
}

// bool rel_pos_is(const char_mat &grid, )

int count_xmas(const char_mat &grid) {
  int count = 0;
  for (auto x_pos : find_coords(grid, 'X')) {
    for (auto m_pos : find_near(grid, 'M', x_pos)) {
      auto direction = m_pos - x_pos;
      //                if (find_as(grid, m_pos, direction)) {
      //                  count++;
      //                }
    }
  }

  return count;
}

long part1(const std::string &filename) {
  return count_xmas(readCharMatrix(PARENT_DIR "/" + filename));
}

long part2(const std::string &filename) { return 0; }
