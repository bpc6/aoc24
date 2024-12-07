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

  class Iterator {
  private:
    std::vector<std::vector<char>>::iterator
        row_it; // Iterator to the current row
    std::vector<std::vector<char>>::iterator row_end; // End iterator for rows
    std::vector<char>::iterator col_it; // Iterator to the current column

    void advance_to_next_valid_row();

  public:
    Iterator(std::vector<std::vector<char>>::iterator r_it,
             std::vector<std::vector<char>>::iterator r_end,
             std::vector<char>::iterator c_it);
    char &operator*() const;
    Iterator &operator++();
    bool operator!=(const Iterator &other) const;
  };

  Iterator begin() {
    return Iterator(grid_.begin(), grid_.end(), grid_.begin()->begin());
  }
  Iterator end() {
    return Iterator(grid_.end(), grid_.end(), std::vector<char>::iterator{});
  }
};
