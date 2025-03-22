#include "day15.h"
#include "parsing.h"
#include <ranges>
#include <stdexcept>

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

std::string WarehouseBotEnv::to_string() {
  std::string s;
  for (int y : std::views::iota(0, shape_.y())) {
    for (int x : std::views::iota(0, shape_.x())) {
      if (map_.contains({x, y}))
        s += to_char_(map_[{x, y}]);
      else if (pos_ == Coord{x, y})
        s += '@';
      else
        s += '.';
    }
    s += '\n';
  }
  return s;
}
char WarehouseBotEnv::to_char_(WarehouseBotEnv::Content cont) {
  if (cont == WALL)
    return '#';
  if (cont == CRATE)
    return 'O';
  throw std::invalid_argument("Only WALL or CRATE");
}
