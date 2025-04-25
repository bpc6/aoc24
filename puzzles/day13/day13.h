#ifndef AOC24_DAY13_H
#define AOC24_DAY13_H

#include <Eigen/Dense>
#include <string>
#include <vector>

using Vec = Eigen::Matrix<size_t, 2, 1>;

/**
 * Determine the fewest tokens required to win all possible prizes. Some prizes
 * are not reachable.
 *
 * Button A costs 3, button B costs 1 token.
 * Both buttons move a configurable amount right and forward.
 * Prize is at a stated position.
 */
size_t part1(const std::string &filename);

/**
 * Add 10000000000000 to the X and Y value of the prize.
 */
size_t part2(const std::string &filename);

size_t numeric_only(const std::string &s);
size_t cost_of_prize(const Vec &dir_a, const Vec &dir_b, const Vec &prize);

#endif // AOC24_DAY13_H
