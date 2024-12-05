#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <optional>
#include <string>
#include <utility>
#include <vector>

using char_mat = std::vector<std::vector<char>>;
std::vector<std::pair<int, int>> find_coords(const char_mat &grid, char c);
std::vector<std::pair<int, int>> find_near(const char_mat &grid, char c,
                                           std::pair<int, int> target);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
