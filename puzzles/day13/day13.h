#ifndef AOC24_DAY13_H
#define AOC24_DAY13_H

#include <Eigen/Dense>
#include <string>
#include <vector>

size_t part1(const std::string &filename);
size_t part2(const std::string &filename);

size_t cost_of_prize(const Eigen::Vector2i &dir_a, const Eigen::Vector2i &dir_b,
                     const Eigen::Vector2i &prize, const int a_depth,
                     const int b_depth);

#endif // AOC24_DAY13_H
