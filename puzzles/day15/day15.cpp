#include "day15.h"
#include "parsing.h"

size_t part1(const std::string &filename) { return 0; }

size_t part2(const std::string &filename) { return 0; }

WarehouseBotEnv::WarehouseBotEnv(Coord shape,
                                 std::initializer_list<Coord> walls,
                                 std::initializer_list<Coord> crates,
                                 Coord init_pos)
    : shape_(shape), pos_(init_pos) {
  for (const auto &wall : walls) {
    map_[wall] = WALL;
  }
  for (const auto &crate : crates) {
    map_[crate] = CRATE;
  }
}
