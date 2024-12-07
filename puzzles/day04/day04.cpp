#include "day04.h"
#include "parsing.h"
#include <algorithm>
#include <ranges>

int count_xmas(const CharGrid &grid) {
  int count = 0;
  for (auto x_pos : grid.find_coords('X')) {
    for (auto m_pos : grid.find_near('M', x_pos)) {
      auto direction = m_pos - x_pos;
      auto a_pos = m_pos + direction;
      auto s_pos = a_pos + direction;
      if (grid.has_coord(a_pos) && grid[a_pos] == 'A' &&
          grid.has_coord(s_pos) && grid[s_pos] == 'S') {
        count++;
      }
    }
  }
  return count;
}

int count_x_mas(const CharGrid &grid) {
  int count = 0;
  for (auto a_pos : grid.find_coords('A')) {
    int mas_count = 0;
    for (auto m_pos : grid.find_near('M', a_pos)) {
      auto direction = m_pos - a_pos;
      if (direction.cwiseAbs().sum() != 2) {
        // not a corner
        continue;
      }
      auto s_pos = a_pos - direction;
      if (grid.has_coord(s_pos) && grid[s_pos] == 'S') {
        ++mas_count;
      }

      if (mas_count == 2) {
        count++;
      }
    }
  }
  return count;
}

long part1(const std::string &filename) {
  return count_xmas(readCharMatrix(PARENT_DIR "/" + filename));
}

long part2(const std::string &filename) {
  return count_x_mas(readCharMatrix(PARENT_DIR "/" + filename));
}

CharGrid::CharGrid(const char_mat &&char_grid) : grid(std::move(char_grid)) {}
char &CharGrid::operator[](Eigen::Vector2i coord) {
  return grid[coord.y()][coord.x()];
}
const char &CharGrid::operator[](Eigen::Vector2i coord) const {
  return grid[coord.y()][coord.x()];
}
std::vector<Eigen::Vector2i> CharGrid::find_coords(char c) const {
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
std::vector<Eigen::Vector2i>
CharGrid::find_near(char c, const Eigen::Vector2i &target) const {
  std::vector<Eigen::Vector2i> result;
  for (auto y = std::max(0, target.y() - 1);
       y < std::min(static_cast<int>(grid.size()), target.y() + 2); ++y) {
    for (auto x = std::max(0, target.x() - 1);
         x < std::min(static_cast<int>(grid[y].size()), target.x() + 2); ++x) {
      if ((*this)[{x, y}] == c) {
        result.push_back({x, y});
      }
    }
  }
  return result;
}
bool CharGrid::has_coord(const Eigen::Vector2i &coord) const {
  return coord.y() >= 0 && coord.y() < grid.size() && coord.x() >= 0 &&
         coord.x() < grid[coord.y()].size();
}
