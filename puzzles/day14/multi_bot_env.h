#ifndef AOC24_MULTI_BOT_ENV_H
#define AOC24_MULTI_BOT_ENV_H

#include "bot_env.h"
#include <initializer_list>
#include <string>
#include <vector>

class MultiBotEnv {
public:
  MultiBotEnv(int width, int height, std::initializer_list<Vec> initial);
  MultiBotEnv(int width, int height,
              const std::vector<std::string> &bot_states);

  void step();

  /**
   * Multiplies the number of bots in each quadrant. Ignore bots exactly in the
   * middle (horiz or vertical).
   */
  int safety_factor() const;
  [[nodiscard]] bool all_unique() const;

private:
  std::vector<BotEnv> envs_;
  int height_;
  int width_;
};

#endif // AOC24_MULTI_BOT_ENV_H
