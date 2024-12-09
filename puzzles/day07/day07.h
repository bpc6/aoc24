#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <functional>
#include <string>
#include <vector>

std::vector<std::vector<std::function<long(long, long)>>>
op_combos(size_t slots,
          const std::vector<std::function<long(long, long)>> &operators);

bool solvable(long solution, const std::vector<int> &numbers,
              const std::vector<std::function<long(long, long)>> &operators);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
