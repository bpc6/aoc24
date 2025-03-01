#ifndef AOC24_DAY14_H
#define AOC24_DAY14_H

#include <Eigen/Dense>
#include <string>

using Vec = Eigen::Vector2i;

size_t part1(const std::string &filename, int width, int height);
size_t part2(const std::string &filename, int width, int height);

class BotEnv {
public:
  BotEnv(int width, int height, Vec pos, Vec velo);
  BotEnv(int width, int height, Vec pos)
      : BotEnv(width, height, pos, Vec(0, 0)) {}
  void step();
  Vec pos() const;

private:
  void wrap_back_to_grid_();

  int width_;
  int height_;
  Vec pos_;
  Vec velo_;
};

BotEnv bot_env_factory(int w, int h, const std::string &s);

class MultiBotEnv {
public:
  MultiBotEnv(int width, int height, std::initializer_list<Vec> initial)
      : width_(width), height_(height) {
    for (const auto &pos : initial) {
      envs_.emplace_back(width, height, pos);
    }
  }
  MultiBotEnv(int width, int height, const std::vector<std::string> &bot_states)
      : width_(width), height_(height) {
    for (const auto &line : bot_states) {
      envs_.emplace_back(bot_env_factory(width, height, line));
    }
  }

  void step();
  int safety_factor() const;

private:
  std::vector<BotEnv> envs_;
  int height_;
  int width_;
};

#endif // AOC24_DAY14_H
