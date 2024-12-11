#include <Eigen/Dense>
#include <ranges>
#include <set>
#include <string>
#include <vector>

template <typename T> class Grid {
protected:
  using vec2d = std::vector<std::vector<T>>;
  vec2d grid_{};

public:
  explicit Grid(const vec2d &&grid) : grid_(std::move(grid)) {}
  explicit Grid(size_t height, size_t width, T initial) {
    for (size_t i = 0; i < height; ++i) {
      grid_.push_back(std::vector<T>(width, initial));
    }
  }

  T &operator[](Eigen::Vector2i coord) { return grid_[coord.y()][coord.x()]; }

  const T &operator[](Eigen::Vector2i coord) const {
    return grid_[coord.y()][coord.x()];
  }

  [[nodiscard]] size_t height() const { return grid_.size(); }
  [[nodiscard]] size_t width() const { return grid_[0].size(); }
  [[nodiscard]] size_t size() const { return this->height() * this->width(); }

  [[nodiscard]] bool has_coord(const Eigen::Vector2i &coord) const {
    return coord.y() >= 0 && coord.y() < this->height() && coord.x() >= 0 &&
           coord.x() < this->width();
  }

  [[nodiscard]] std::vector<Eigen::Vector2i> find_coords(T match) const {
    std::vector<Eigen::Vector2i> result;
    for (auto const [y, row] : std::views::enumerate(grid_)) {
      for (auto const [x, val] : std::views::enumerate(row)) {
        if (val == match) {
          result.push_back({x, y});
        }
      }
    }
    return result;
  }

  [[nodiscard]] std::vector<T> find_unique() const {
    std::set<T> s;
    for (auto const row : grid_) {
      for (auto const val : row) {
        s.insert(val);
      }
    }
    return {s.begin(), s.end()};
  }

  [[nodiscard]] std::vector<Eigen::Vector2i>
  find_near(T c, const Eigen::Vector2i &target) const {
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
};
