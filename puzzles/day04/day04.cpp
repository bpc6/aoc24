#include "day04.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>


bool find_in_grid::operator()(std::pair<size_t, size_t> &dest) {
    while (curr.first < grid.size()) {
        while (curr.second < grid[curr.first].size()) {
            if (grid[curr.first][curr.second] == c) {
                dest = curr;
                curr.second++;
                return true;
            }
            curr.second++;
        }
        curr.second = 0;
        curr.first++;
    }
    return false;
}


int count_xmas(const char_mat &grid) {
    std::pair<size_t, size_t> x_pos;

//    while (find_in_grid(grid)(x_pos, 'X')) {
//        if (find_m(grid, x_pos, m_pos)) {
//            direction = m_pos - x_pos;
//            if (find_as(grid, m_pos, direction)) {
//                count++;
//            }
//        }
//    }

    return 0;
}

long part1(const std::string &filename) {
    return count_xmas(readCharMatrix(PARENT_DIR "/" + filename));
}

long part2(const std::string &filename) { return 0; }
