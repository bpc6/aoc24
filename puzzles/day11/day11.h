#ifndef AOC24_DAY11_H
#define AOC24_DAY11_H

#include <string>
#include <vector>

/**
 * Count the number of stones after 25 updates.
 *
 * Stones split according to the following rules:
 *  - 0 -> 1
 *  - Even # of digits -> 2 stones, one with left half, other with right
 *  - Otherwise, *= 2024
 */
size_t part1(const std::string &filename);

/**
 * Count the number of stones after 75 updates.
 */
size_t part2(const std::string &filename);

std::pair<unsigned long, unsigned long> split_digits(unsigned long n);

#endif // AOC24_DAY11_H
