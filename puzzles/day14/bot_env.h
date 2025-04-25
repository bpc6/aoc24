#ifndef AOC24_BOT_ENV_H
#define AOC24_BOT_ENV_H

#include <Eigen/Dense>

using Vec = Eigen::Vector2i;

class BotEnv {
public:
  BotEnv(int width, int height, Vec pos, Vec velo);
  BotEnv(int width, int height, Vec pos)
      : BotEnv(width, height, std::move(pos), Vec(0, 0)) {}
  void step();
  [[nodiscard]] Vec pos() const;

private:
  void wrap_back_to_grid_();

  int width_;
  int height_;
  Vec pos_;
  Vec velo_;
};

BotEnv bot_env_factory(int w, int h, const std::string &s);

#endif // AOC24_BOT_ENV_H
