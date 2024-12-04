#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <string>
#include <vector>

std::vector<int> drop_ith(const std::vector<int> &v, std::size_t i);

template <std::ranges::range R> bool is_safe(const R &level);
bool is_safe_after_removal(const std::vector<int> &level);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
