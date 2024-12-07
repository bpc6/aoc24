#include "char_grid.h"
#include <ranges>

CharGrid::CharGrid(const char_mat &&char_grid) : grid_(std::move(char_grid)) {}
char &CharGrid::operator[](Eigen::Vector2i coord) {
  return grid_[coord.y()][coord.x()];
}
const char &CharGrid::operator[](Eigen::Vector2i coord) const {
  return grid_[coord.y()][coord.x()];
}
size_t CharGrid::height() const { return grid_.size(); }
size_t CharGrid::width() const { return grid_[0].size(); }
std::vector<Eigen::Vector2i> CharGrid::find_coords(char c) const {
  std::vector<Eigen::Vector2i> result;
  for (auto const [y, row] : std::views::enumerate(grid_)) {
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
       y < std::min(static_cast<int>(this->height()), target.y() + 2); ++y) {
    for (auto x = std::max(0, target.x() - 1);
         x < std::min(static_cast<int>(this->width()), target.x() + 2); ++x) {
      if ((*this)[{x, y}] == c) {
        result.push_back({x, y});
      }
    }
  }
  return result;
}
bool CharGrid::has_coord(const Eigen::Vector2i &coord) const {
  return coord.y() >= 0 && coord.y() < grid_.size() && coord.x() >= 0 &&
         coord.x() < grid_[coord.y()].size();
}
