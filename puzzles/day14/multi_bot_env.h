#ifndef AOC24_MULIT_BOT_ENV_H
#define AOC24_MULIT_BOT_ENV_H

#include "bot_env.h"
#include <initializer_list>
#include <string>
#include <vector>

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
  [[nodiscard]] bool all_unique() const;

private:
  std::vector<BotEnv> envs_;
  int height_;
  int width_;
};

#endif // AOC24_MULIT_BOT_ENV_H
