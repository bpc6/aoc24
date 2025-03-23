#include "day15.h"
#include "parsing.h"
#include <ranges>
#include <stdexcept>

size_t part1(const std::string &filename) { return 0; }

size_t part2(const std::string &filename) { return 0; }

int gps_coordinate(const Coord &c) { return 100 * c.y() + c.x(); }

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
  if (can_move_(dir)) {
    shift_crates_(dir);
    set_pos(pos_ + dir);
  }
}
bool WarehouseBotEnv::can_move_(const Coord &dir) {
  auto target = (pos_ + dir).eval();
  while (is_crate(target))
    target += dir;
  return !is_wall(target);
}
void WarehouseBotEnv::shift_crates_(const Coord &dir) {
  auto target = (pos_ + dir).eval();
  std::vector<Coord> shifted;
  while (is_crate(target)) {
    auto it = crates_.find(target);
    crates_.erase(it);
    shifted.emplace_back(target + dir);
    target += dir;
  }
  crates_.insert(shifted.begin(), shifted.end());
}
