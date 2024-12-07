#include <Eigen/Dense>
#include <string>
#include <vector>

class Grid {
protected:
  using vec2d = std::vector<std::vector<char>>;
  vec2d grid_;

public:
  explicit Grid(const vec2d &&grid);
  char &operator[](Eigen::Vector2i coord);
  const char &operator[](Eigen::Vector2i coord) const;
  size_t height() const;
  size_t width() const;
  size_t size() const;

  [[nodiscard]] bool has_coord(const Eigen::Vector2i &coord) const;
  [[nodiscard]] std::vector<Eigen::Vector2i> find_coords(char c) const;
  [[nodiscard]] std::vector<Eigen::Vector2i>
  find_near(char c, const Eigen::Vector2i &target) const;
};
