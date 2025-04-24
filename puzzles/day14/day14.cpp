#include "day14.h"
#include "parsing.h"
#include <ranges>
#include <unordered_set>
#include <utility>

size_t part1(const std::string &filename, int width, int height) {
  MultiBotEnv env{width, height, readLines(PARENT_DIR "/" + filename)};
  for (int i : std::views::iota(0, 100))
    env.step();
  return env.safety_factor();
}

size_t part2(const std::string &filename, int width, int height) {
  MultiBotEnv env{width, height, readLines(PARENT_DIR "/" + filename)};
  size_t count = 0;
  while (!env.all_unique()) {
    env.step();
    count += 1;
  }
  return count;
}

int MultiBotEnv::safety_factor() const {
  std::vector<int> counts{0, 0, 0, 0};
  for (const auto &env : envs_) {
    int quad = 0;
    if (env.pos().x() == width_ / 2 or env.pos().y() == height_ / 2)
      continue;
    if (env.pos().x() > width_ / 2)
      quad += 1;
    if (env.pos().y() > height_ / 2)
      quad += 2;
    counts[quad] += 1;
  }
  return std::ranges::fold_left(counts, 1, std::multiplies<>{});
}

void MultiBotEnv::step() {
  for (auto &env : envs_) {
    env.step();
  }
}

namespace std {
template <> struct hash<Eigen::Vector2i> {
  std::size_t operator()(const Eigen::Vector2i &v) const {
    return std::hash<int>()(v.x()) ^ (std::hash<int>()(v.y()) << 1);
  }
};
} // namespace std

bool MultiBotEnv::all_unique() const {
  auto pos_views =
      envs_ | std::views::transform([](const auto &env) { return env.pos(); });

  std::unordered_set<Vec> seen;
  for (const auto &pos : pos_views) {
    if (!seen.insert(pos).second) {
      return false;
    }
  }
  return true;
}
