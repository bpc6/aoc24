#ifndef AOC24_DAY14_H
#define AOC24_DAY14_H

#include <Eigen/Dense>
#include <string>

size_t part1(const std::string &filename, int width, int height);
size_t part2(const std::string &filename, int width, int height);

using Vec = Eigen::Vector2i;

class BotEnv {
public:
  BotEnv(int width, int height, Vec pos, Vec velo);
  void step();
};

#endif // AOC24_DAY14_H
