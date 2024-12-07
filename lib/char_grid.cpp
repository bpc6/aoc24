#include "char_grid.h"
#include <ranges>

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
