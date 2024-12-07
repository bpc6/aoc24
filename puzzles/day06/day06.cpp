#include "day06.h"
#include "grid.h"
#include "parsing.h"

Eigen::Vector2i rotate(const Eigen::Vector2i &dir) {
  Eigen::Matrix2i rot{{0, -1}, {1, 0}};
  return rot * dir;
}

int count_visited(const Grid<char> &grid) {
  Grid<int> visited(grid.height(), grid.width(), 0);
  auto curr = grid.find_coords('^')[0];
  Eigen::Vector2i direction{0, -1}, next;

  while (grid.has_coord(next = curr + direction)) {
    visited[curr] = 1;
    if (grid[next] == '#') {
      direction = rotate(direction);
    } else {
      curr = next;
    }
  }

  return 1 + visited.find_coords(1).size();
}

long part1(const std::string &filename) {
  return count_visited(Grid<char>(readCharMatrix(PARENT_DIR "/" + filename)));
}

long part2(const std::string &filename) { return 0; }
