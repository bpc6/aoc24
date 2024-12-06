#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <Eigen/Dense>
#include <optional>
#include <string>
#include <utility>
#include <vector>

using char_mat = std::vector<std::vector<char>>;
std::vector<Eigen::Vector2i> find_coords(const char_mat &grid, char c);
std::vector<Eigen::Vector2i> find_near(const char_mat &grid, char c,
                                       Eigen::Vector2i target);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
