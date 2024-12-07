#include "char_grid.h"
#include <ranges>

Grid::Grid(const vec2d &&char_grid) : grid_(std::move(char_grid)) {}

char &Grid::operator[](Eigen::Vector2i coord) {
  return grid_[coord.y()][coord.x()];
}

const char &Grid::operator[](Eigen::Vector2i coord) const {
  return grid_[coord.y()][coord.x()];
}

size_t Grid::height() const { return grid_.size(); }

size_t Grid::width() const { return grid_[0].size(); }

size_t Grid::size() const { return this->height() * this->width(); }

std::vector<Eigen::Vector2i> Grid::find_coords(char c) const {
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
Grid::find_near(char c, const Eigen::Vector2i &target) const {
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

bool Grid::has_coord(const Eigen::Vector2i &coord) const {
  return coord.y() >= 0 && coord.y() < grid_.size() && coord.x() >= 0 &&
         coord.x() < grid_[coord.y()].size();
}
