#include "day06.h"
#include "grid.h"
#include "parsing.h"

Eigen::Vector2i rotate(const Eigen::Vector2i &dir) {
  Eigen::Matrix2i rot{{0, -1}, {1, 0}};
  return rot * dir;
}

size_t count_visited(const Grid<char> &grid) {
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

int check_for_loop(const Grid<char> &grid,
                   const Grid<std::vector<Eigen::Vector2i>> &visited,
                   Eigen::Vector2i curr, const Eigen::Vector2i &dir) {
  auto new_dir = rotate(dir);
  Eigen::Vector2i next;
  while (grid.has_coord(next = curr + new_dir) && grid[next] != '#') {
    if (std::find(visited[curr].begin(), visited[curr].end(), new_dir) !=
        visited[curr].end()) {
      return 1;
    }
    curr = next;
  }
  return 0;
}

int count_loopers(Grid<char> grid) {
  Grid<std::vector<Eigen::Vector2i>> visited(grid.height(), grid.width(), {});
  auto curr = grid.find_coords('^')[0];
  Eigen::Vector2i direction{0, -1}, next;

  int counter = 0;

  while (grid.has_coord(next = curr + direction)) {
    if (grid[next] == '#') {
      direction = rotate(direction);
    } else {
      counter += check_for_loop(grid, visited, curr, direction);
      curr = next;
    }
    visited[curr].push_back(direction);
  }
  return counter;
}

long part1(const std::string &filename) {
  return count_visited(Grid<char>(readCharMatrix(PARENT_DIR "/" + filename)));
}

long part2(const std::string &filename) {
  return count_loopers(Grid<char>(readCharMatrix(PARENT_DIR "/" + filename)));
}
