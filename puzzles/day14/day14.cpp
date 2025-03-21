#include "day14.h"
#include "parsing.h"
#include <algorithm>
#include <ranges>

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

Vec vec_from_string(const std::string s) {
  auto int_vec = ints(split(s, '=')[1], ',');
  return {int_vec[0], int_vec[1]};
}

BotEnv bot_env_factory(int w, int h, const std::string &s) {
  return BotEnv(w, h, vec_from_string(split(s)[0]),
                vec_from_string(split(s)[1]));
}

BotEnv::BotEnv(int width, int height, Vec pos, Vec velo)
    : width_(width), height_(height), pos_(pos), velo_(velo) {}

void BotEnv::step() {
  pos_ += velo_;
  wrap_back_to_grid_();
}

Vec BotEnv::pos() const { return pos_; }

void BotEnv::wrap_back_to_grid_() {
  while (pos_.x() < 0)
    pos_ += Vec{width_, 0};
  while (pos_.x() >= width_)
    pos_ -= Vec{width_, 0};
  while (pos_.y() < 0)
    pos_ += Vec{0, height_};
  while (pos_.y() >= height_)
    pos_ -= Vec{0, height_};
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

bool MultiBotEnv::all_unique() const {
  auto pos_views =
      envs_ | std::views::transform([](auto env) { return env.pos(); });
  std::vector<Vec> positions{pos_views.begin(), pos_views.end()};
  auto vec_compare = [](const Vec &a, const Vec &b) {
    if (a.x() == b.x())
      return a.y() < b.y();
    return a.x() < b.x();
  };
  std::ranges::sort(positions, vec_compare);
  auto [ret, last] = std::ranges::unique(positions);
  return ret == positions.end();
}
