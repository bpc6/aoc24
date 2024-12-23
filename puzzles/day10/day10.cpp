#include "day10.h"
#include "grid.h"
#include "parsing.h"
#include <Eigen/Dense>
#include <stack>

size_t count_trails_to_9(const Grid<int> &grid, Eigen::Vector2i curr) {
  std::stack<Eigen::Vector2i> stack;
  stack.push(curr);

  std::vector<Eigen::Vector2i> seen;
  size_t count = 0;
  while (!stack.empty()) {
    curr = stack.top();
    stack.pop();

    if (grid[curr] == 9 && std::ranges::find(seen, curr) == seen.end()) {
      seen.push_back(curr);
      count += 1;
    } else {
      for (const auto &dir : grid.directions()) {
        const auto next = (curr + dir).eval();
        if (grid.has_coord(curr + dir) && grid[curr + dir] == grid[curr] + 1) {
          stack.emplace(curr + dir);
        }
      }
    }
  }
  return count;
}

size_t count_trail_scores(const Grid<int> &grid) {
  std::stack<Eigen::Vector2i> stack;
  size_t count = 0;
  for (const auto &z : grid.find_coords(0)) {
    count += count_trails_to_9(grid, z);
  }
  return count;
}

size_t part1(const std::string &filename) {
  return count_trail_scores(Grid(readIntMatrix(PARENT_DIR "/" + filename)));
}

size_t part2(const std::string &filename) { return 0; }
