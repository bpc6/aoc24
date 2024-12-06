#ifndef AOC24_DAY05_H
#define AOC24_DAY05_H

#include <map>
#include <string>
#include <vector>

std::map<int, std::vector<int>> read_map(const std::vector<std::string> &lines);
std::vector<std::vector<int>>
read_page_updates(const std::vector<std::string> &lines);
bool correct_order(const std::vector<int> &update,
                   std::map<int, std::vector<int>> &rules);
std::vector<int> fix_order(const std::vector<int> &update,
                           std::map<int, std::vector<int>> &rules);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY05_H
