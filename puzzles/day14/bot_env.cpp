#include "bot_env.h"
#include "parsing.h"

Vec vec_from_string(const std::string &s) {
  auto int_vec = ints(split(s, '=')[1], ',');
  return {int_vec[0], int_vec[1]};
}

BotEnv bot_env_factory(int w, int h, const std::string &s) {
  return {w, h, vec_from_string(split(s)[0]), vec_from_string(split(s)[1])};
}

BotEnv::BotEnv(int width, int height, Vec pos, Vec velo)
    : width_(width), height_(height), pos_(std::move(pos)),
      velo_(std::move(velo)) {}

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
