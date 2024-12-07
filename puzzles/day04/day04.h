#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <Eigen/Dense>
#include <optional>
#include <string>
#include <utility>
#include <vector>

using char_mat = std::vector<std::vector<char>>;

class CharGrid {
private:
  char_mat grid;

public:
  CharGrid(const char_mat &&char_grid);
  char &operator[](Eigen::Vector2i coord);
  const char &operator[](Eigen::Vector2i coord) const;
  bool has_coord(const Eigen::Vector2i &coord) const;

  std::vector<Eigen::Vector2i> find_coords(char c) const;
  std::vector<Eigen::Vector2i> find_near(char c,
                                         const Eigen::Vector2i &target) const;
};

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
