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
        for (const auto p : {coord - next, next - coord}) {
          if (grid.has_coord(p) && std::ranges::find(found, p) == found.end()) {
            found.push_back(p);
          }
        }
      }
    }
  }
  return found.size();
}

long part2(const std::string &filename) { return 0; }
