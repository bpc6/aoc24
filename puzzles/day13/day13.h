#ifndef AOC24_DAY13_H
#define AOC24_DAY13_H

#include <Eigen/Dense>
#include <string>
#include <vector>

using Vec = Eigen::Matrix<size_t, 2, 1>;

size_t part1(const std::string &filename);
size_t part2(const std::string &filename);

size_t numeric_only(const std::string &s);
size_t cost_of_prize(const Vec &dir_a, const Vec &dir_b, const Vec &prize);

#endif // AOC24_DAY13_H
