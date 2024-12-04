#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <string>
#include <utility>
#include <vector>

using char_mat = std::vector<std::vector<char>>;

class find_in_grid {
    std::pair<size_t, size_t> curr;
    const char_mat grid;
    const char c;
public:
    explicit find_in_grid(char_mat grid, char c) : curr(0, 0), grid(std::move(grid)), c(c) {};
    bool operator()(std::pair<size_t, size_t> &dest);
};

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
