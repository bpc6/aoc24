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

#endif // AOC24_DAY14_H
