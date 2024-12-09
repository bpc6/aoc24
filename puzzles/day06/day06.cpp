#include "day06.h"
#include "grid.h"
#include "parsing.h"
#include <map>
#include <set>

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

struct Vector2iCompare {
  bool operator()(const Eigen::Vector2i &a, const Eigen::Vector2i &b) const {
    if (a.x() != b.x())
      return a.x() < b.x();
    return a.y() < b.y();
  }
};

int check_for_loop(
    Grid<char> grid,
    std::map<Eigen::Vector2i, std::set<Eigen::Vector2i, Vector2iCompare>,
             Vector2iCompare>
        obstacles,
    Eigen::Vector2i curr, Eigen::Vector2i direction) {
  grid[curr + direction] = '#';
  Eigen::Vector2i next;
  while (grid.has_coord(next = curr + direction)) {
    auto x = curr.x();
    auto y = curr.y();
    if (grid[next] == '#') {
      if (obstacles[next].contains(direction)) {
        return 1;
      }
      obstacles[next].insert(direction);
      direction = rotate(direction);
    } else {
      curr = next;
    }
  }
  return 0;
}

int count_loopers(const Grid<char> &grid) {
  std::map<Eigen::Vector2i, std::set<Eigen::Vector2i, Vector2iCompare>,
           Vector2iCompare>
      obstacles;
  auto curr = grid.find_coords('^')[0];
  Eigen::Vector2i direction{0, -1}, next;

  int counter = 0;

  while (grid.has_coord(next = curr + direction)) {
    auto x = curr.x();
    auto y = curr.y();
    if (grid[next] == '#') {
      if (obstacles[next].contains(direction)) {
        // loop
      }
      obstacles[next].insert(direction);
      direction = rotate(direction);
    } else {
      counter += check_for_loop(grid, obstacles, curr, direction);
      curr = next;
    }
  }
  return counter;
}

long part1(const std::string &filename) {
  return count_visited(Grid<char>(readCharMatrix(PARENT_DIR "/" + filename)));
}

long part2(const std::string &filename) {
  return count_loopers(Grid<char>(readCharMatrix(PARENT_DIR "/" + filename)));
}
