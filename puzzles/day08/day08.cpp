#include "day08.h"
#include "grid.h"
#include "parsing.h"
#include <algorithm>

long part1(const std::string &filename) {
  Grid grid{readCharMatrix(PARENT_DIR "/" + filename)};

  std::vector<Eigen::Vector2i> found;
  for (const auto c : grid.find_unique()) {
    if (c == '.') {
      continue;
    }

    const auto coords = grid.find_coords(c);
    for (const auto [idx, coord] : std::views::enumerate(coords)) {
      for (const auto next : std::views::drop(coords, idx + 1)) {
        const auto delta = next - coord;
        const std::vector<Eigen::Vector2i> pts{coord - delta, next + delta};
        for (const auto p : pts) {
          if (grid.has_coord(p) && std::ranges::find(found, p) == found.end()) {
            found.push_back(p);
          }
        }
      }
    }
  }
  return found.size();
}

long part2(const std::string &filename) {
  Grid grid{readCharMatrix(PARENT_DIR "/" + filename)};

  std::vector<Eigen::Vector2i> found;
  for (const auto c : grid.find_unique()) {
    if (c == '.') {
      continue;
    }

    const auto coords = grid.find_coords(c);
    for (const auto [idx, coord] : std::views::enumerate(coords)) {
      for (const auto next : std::views::drop(coords, idx + 1)) {
        const auto delta = next - coord;

        int scale = 0;
        Eigen::Vector2i p;
        while (grid.has_coord(p = coord - scale * delta)) {
          if (std::ranges::find(found, p) == found.end()) {
            found.push_back(p);
          }
          ++scale;
        }
        scale = 0;
        while (grid.has_coord(p = next + scale * delta)) {
          if (std::ranges::find(found, p) == found.end()) {
            found.push_back(p);
          }
          ++scale;
        }
      }
    }
  }
  return found.size();
}
