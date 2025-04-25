#include "multi_bot_env.h"
#include <ranges>
#include <unordered_set>

MultiBotEnv::MultiBotEnv(int width, int height,
                         std::initializer_list<Vec> initial)
    : width_(width), height_(height) {
  for (const auto &pos : initial) {
    envs_.emplace_back(width, height, pos);
  }
}

MultiBotEnv::MultiBotEnv(int width, int height,
                         const std::vector<std::string> &bot_states)
    : width_(width), height_(height) {
  for (const auto &line : bot_states) {
    envs_.emplace_back(bot_env_factory(width, height, line));
  }
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
