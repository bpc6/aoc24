#include "day15.h"
#include "parsing.h"
#include <ranges>
#include <stdexcept>

size_t part1(const std::string &filename) { return 0; }

size_t part2(const std::string &filename) { return 0; }

WarehouseBotEnv::WarehouseBotEnv(Coord &&shape,
                                 std::initializer_list<Coord> walls,
                                 std::initializer_list<Coord> crates,
                                 Coord &&init_pos)
    : shape_(std::move(shape)), walls_(walls), crates_(crates),
      pos_(std::move(init_pos)) {}

std::string WarehouseBotEnv::to_string() const {
  std::string s;
  for (int y : std::views::iota(0, shape_.y())) {
    for (int x : std::views::iota(0, shape_.x())) {
      if (is_wall({x, y}))
        s += '#';
      else if (is_crate({x, y}))
        s += 'O';
      else if (pos_ == Coord{x, y})
        s += '@';
      else
        s += '.';
    }
    s += '\n';
  }
  return s;
}
bool WarehouseBotEnv::is_wall(const Coord &c) const {
  return walls_.contains(c);
}
bool WarehouseBotEnv::is_crate(const Coord &c) const {
  return crates_.contains(c);
}
void WarehouseBotEnv::set_pos(const Coord &c) { pos_ = c; }
Coord WarehouseBotEnv::get_pos() const { return pos_; }
void WarehouseBotEnv::step(const Coord &dir) {
  if (move_crate_(pos_ + dir, dir))
    set_pos(pos_ + dir);
}
bool WarehouseBotEnv::move_crate_(const Coord &pos, const Coord &dir) {
  if (is_wall(pos))
    return false;
  if (!is_crate(pos))
    return true;
  if (move_crate_(pos + dir, dir)) {
    auto it = crates_.find(pos);
    crates_.erase(it);
    crates_.insert(pos + dir);
    return true;
  }
  return false;
}
