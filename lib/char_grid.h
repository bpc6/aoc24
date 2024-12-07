#include <Eigen/Dense>
#include <string>
#include <vector>

using char_mat = std::vector<std::vector<char>>;

class CharGrid {
protected:
  char_mat grid_;

public:
  explicit CharGrid(const char_mat &&char_grid);
  char &operator[](Eigen::Vector2i coord);
  const char &operator[](Eigen::Vector2i coord) const;
  size_t height() const;
  size_t width() const;
  [[nodiscard]] bool has_coord(const Eigen::Vector2i &coord) const;

  [[nodiscard]] std::vector<Eigen::Vector2i> find_coords(char c) const;
  [[nodiscard]] std::vector<Eigen::Vector2i>
  find_near(char c, const Eigen::Vector2i &target) const;
};
