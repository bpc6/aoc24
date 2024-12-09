#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <functional>
#include <string>
#include <vector>

std::vector<std::vector<std::function<int(int, int)>>> op_combos(size_t slots);

bool solvable(int solution, const std::vector<int> &numbers);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
