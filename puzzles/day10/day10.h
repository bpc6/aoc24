#ifndef AOC24_DAY10_H
#define AOC24_DAY10_H

#include <string>
#include <vector>

/**
 * Count # of 9s reachable from 0, increasing by 1
 *
 * For example, this has 2:
 *  ...0...
 *  ...1...
 *  ...2...
 *  6543456
 *  7.....7
 *  8.....8
 *  9.....9
 */
size_t part1(const std::string &filename);

/**
 * Count the number of distinct paths from 0 to 9, increasing by 1
 *
 * For example, this has 3:
 *  .....0.
 *  ..4321.
 *  ..5..2.
 *  ..6543.
 *  ..7..4.
 *  ..8765.
 *  ..9....
 */
size_t part2(const std::string &filename);

#endif // AOC24_DAY10_H
