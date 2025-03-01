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
  MultiBotEnv(int width, int height, std::vector<Vec> initial) {}

private:
  std::vector<BotEnv> envs_;
};

#endif // AOC24_DAY14_H
