#ifndef AOC24_DAY15_H
#define AOC24_DAY15_H

#include <Eigen/Dense>
#include <string>

using Vec = Eigen::Vector2i;

size_t part1(const std::string &filename);
size_t part2(const std::string &filename);

class WarehouseBotEnv {
public:
  WarehouseBotEnv(std::initializer_list<Vec> walls,
                  std::initializer_list<Vec> crates, Vec init_pos);
};

#endif // AOC24_DAY15_H
