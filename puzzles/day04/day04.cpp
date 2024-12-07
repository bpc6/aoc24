#include "day04.h"
#include "char_grid.h"
#include "parsing.h"

int count_xmas(const CharGrid &grid) {
  int count = 0;
  for (auto x_pos : grid.find_coords('X')) {
    for (auto m_pos : grid.find_near('M', x_pos)) {
      auto direction = m_pos - x_pos;
      auto a_pos = m_pos + direction;
      auto s_pos = a_pos + direction;
      if (grid.has_coord(a_pos) && grid[a_pos] == 'A' &&
          grid.has_coord(s_pos) && grid[s_pos] == 'S') {
        count++;
      }
    }
  }
  return count;
}

int count_x_mas(const CharGrid &grid) {
  int count = 0;
  for (auto a_pos : grid.find_coords('A')) {
    int mas_count = 0;
    for (auto m_pos : grid.find_near('M', a_pos)) {
      auto direction = m_pos - a_pos;
      if (direction.cwiseAbs().sum() != 2) {
        // not a corner
        continue;
      }
      auto s_pos = a_pos - direction;
      if (grid.has_coord(s_pos) && grid[s_pos] == 'S') {
        ++mas_count;
      }

      if (mas_count == 2) {
        count++;
      }
    }
  }
  return count;
}

long part1(const std::string &filename) {
  return count_xmas(CharGrid(readCharMatrix(PARENT_DIR "/" + filename)));
}

long part2(const std::string &filename) {
  return count_x_mas(CharGrid(readCharMatrix(PARENT_DIR "/" + filename)));
}
