#include "day12.h"
#include "grid.h"
#include "parsing.h"
#include <numeric>
#include <stack>

size_t perimeter(const Grid<char> &grid, const Eigen::Vector2i &pos) {
  size_t perim = 0;
  for (const auto &dir : grid.directions()) {
    if (!grid.has_coord(pos + dir) || grid[pos + dir] != grid[pos])
      perim += 1;
  }
  return perim;
}

size_t count_cost(const Grid<char> &grid, char c) {
  size_t total = 0;
  std::vector<Eigen::Vector2i> seen;
  for (const auto &pos : grid.find_coords(c)) {
    if (std::ranges::find(seen, pos) == seen.end()) {
      size_t perim = 0;
      size_t area = 0;

      std::stack<Eigen::Vector2i> stack;
      stack.push(pos);
      while (!stack.empty()) {
        auto curr = stack.top();
        seen.push_back(curr);

        stack.pop();
        area += 1;
        perim += perimeter(grid, curr);
        for (const auto &dir : grid.directions()) {
          if (grid.has_coord(curr + dir) && grid[curr + dir] == c &&
              std::ranges::find(seen, curr + dir) == seen.end()) {
            stack.emplace(curr + dir);
            seen.emplace_back(curr + dir);
          }
        }
      }
      total += perim * area;
    }
  }
  return total;
}

size_t part1(const std::string &filename) {
  Grid<char> grid{readCharMatrix(PARENT_DIR "/" + filename)};

  size_t total = 0;
  for (auto c : grid.find_unique()) {
    total += count_cost(grid, c);
  }

  return total;
}

size_t part2(const std::string &filename) { return 0; }
