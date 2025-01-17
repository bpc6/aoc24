#include "day12.h"
#include "grid.h"
#include "parsing.h"
#include <stack>

std::vector<Eigen::Vector2i> perimeter_coords(const Grid<char> &grid,
                                              const Eigen::Vector2i &pos) {
  std::vector<Eigen::Vector2i> result;
  for (const auto &dir : grid.directions()) {
    if (!grid.has_coord(pos + dir) || grid[pos + dir] != grid[pos])
      result.emplace_back(pos + dir);
  }
  return result;
}

size_t count_cost(const Grid<char> &grid, char c) {
  size_t total = 0;
  Grid<int> seen{grid.height(), grid.width(), 0};
  for (const auto &pos : grid.find_coords(c)) {
    if (!seen[pos]) {
      size_t perim = 0;
      size_t area = 0;

      std::stack<Eigen::Vector2i> stack;
      stack.push(pos);
      while (!stack.empty()) {
        auto curr = stack.top();
        seen[curr] = 1;

        stack.pop();
        area += 1;
        perim += perimeter_coords(grid, curr).size();
        for (const auto &dir : grid.directions()) {
          if (grid.has_coord(curr + dir) && grid[curr + dir] == c &&
              !seen[curr + dir]) {
            stack.emplace(curr + dir);
            seen[curr + dir] = 1;
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

size_t discounted(const Grid<char> &grid, char c) {
  size_t total = 0;
  Grid<int> seen{grid.height(), grid.width(), 0};
  Grid<int> processed{grid.height(), grid.width(), 0};
  for (const auto &pos : grid.find_coords(c)) {
    if (!seen[pos]) {
      size_t perim = 0;
      size_t area = 0;

      std::stack<Eigen::Vector2i> stack;
      stack.push(pos);
      while (!stack.empty()) {
        auto curr = stack.top();
        seen[curr] = 1;
        processed[curr] = 1;

        stack.pop();
        area += 1;

        auto ps = perimeter_coords(grid, curr);
        perim += ps.size();

        std::vector<Eigen::Vector2i> adj_seen;
        for (const auto &dir : grid.directions()) {
          const auto adj = curr + dir;
          if (grid.has_coord(adj) && processed[adj]) {
            adj_seen.emplace_back(adj);
          }
        }

        for (const auto &p : ps) {
          const auto dir_to_p = (p - curr).eval();
          for (const auto adj : adj_seen) {
            const auto adj_ps = perimeter_coords(grid, adj);
            if (std::ranges::find(adj_ps, adj + dir_to_p) != adj_ps.end()) {
              perim -= 1;
            }
          }
        }

        for (const auto &dir : grid.directions()) {
          const auto next = curr + dir;
          if (grid.has_coord(next) && grid[next] == c && !seen[next]) {
            stack.emplace(next);
            seen[next] = 1;
          }
        }
      }
      total += perim * area;
    }
  }
  return total;
}

size_t part2(const std::string &filename) {
  Grid<char> grid{readCharMatrix(PARENT_DIR "/" + filename)};

  size_t total = 0;
  for (auto c : grid.find_unique()) {
    total += discounted(grid, c);
  }

  return total;
}
