#include "day10.h"
#include "grid.h"
#include "parsing.h"
#include <Eigen/Dense>
#include <stack>

size_t count_trails_to_9(const Grid<int> &grid, Eigen::Vector2i curr) {
  std::stack<Eigen::Vector2i> stack;
  stack.push(curr);

  size_t count = 0;
  while (!stack.empty()) {
    curr = stack.top();
    stack.pop();

    if (grid[curr] == 9) {
      count += 1;
    } else {
      for (const auto &dir : grid.directions()) {
        if (grid.has_coord(curr + dir) && grid[curr + dir] == grid[curr] + 1) {
          stack.emplace(curr + dir);
        }
      }
    }
  }
  return count;
}

size_t count_trail_ratings(const Grid<int> &grid) {
  return std::ranges::fold_left(
      grid.find_coords(0) | std::views::transform([&grid](const auto &coord) {
        return count_trails_to_9(grid, coord);
      }),
      0, std::plus<>{});
}

size_t count_trail_scores(const Grid<int> &grid) {
  return std::ranges::fold_left(
      grid.find_coords(0) | std::views::transform([&grid](const auto &coord) {
        return count_trails_to_9(grid, coord);
      }),
      0, std::plus<>{});
}

size_t part1(const std::string &filename) {
  return count_trail_scores(Grid(readIntMatrix(PARENT_DIR "/" + filename)));
}

size_t part2(const std::string &filename) {
  return count_trail_ratings(Grid(readIntMatrix(PARENT_DIR "/" + filename)));
}
