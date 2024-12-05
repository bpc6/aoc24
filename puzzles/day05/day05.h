#ifndef AOC24_DAY05_H
#define AOC24_DAY05_H

#include <string>
#include <vector>

std::vector<std::pair<int, int>> read_rules(const std::vector<std::string> &lines);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY05_H
