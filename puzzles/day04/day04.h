#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <string>
#include <utility>
#include <vector>

using char_mat = std::vector<std::vector<char>>;

class find_in_grid {
    std::pair<size_t, size_t> curr;
    const char_mat grid;
public:
    explicit find_in_grid(char_mat grid) : grid(std::move(grid)), curr(0, 0) {};
    bool operator()(std::pair<size_t, size_t> &dest, char c);
};

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
