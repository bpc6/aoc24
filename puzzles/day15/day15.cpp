#include "day15.h"
#include "parsing.h"
#include <ranges>
#include <stdexcept>

size_t part1(const std::string &filename) {
  const auto txt = readFile(PARENT_DIR "/" + filename);
  const auto grid = split(txt, "\n\n")[0];
  const auto dirs = split(txt, "\n\n").back();
  auto env = from_string(grid);
  for (const auto c : dirs)
    env.step(from_char(c));
  return env.sum_gps();
}

size_t part2(const std::string &filename) { return 0; }

int gps_coordinate(const Coord &c) { return 100 * c.y() + c.x(); }
Coord from_char(char c) {
  if (c == '<')
    return {-1, 0};
  if (c == '>')
    return {1, 0};
  if (c == '^')
    return {0, -1};
  if (c == 'v')
    return {0, 1};
  return {0, 0};
}

WarehouseBotEnv from_string(std::string s) {
  std::unordered_set<Coord> walls, crates;
  Coord init_pos = {-1, -1};
  for (const auto &[y, line] : split(s) | std::views::enumerate) {
    for (const auto &[x, c] : line | std::views::enumerate) {
      if (c == '#')
        walls.emplace(x, y);
      else if (c == 'O')
        crates.emplace(x, y);
      else if (c == '@')
        init_pos = {x, y};
    }
  }
  return WarehouseBotEnv({split(s)[0].length(), split(s).size()}, walls, crates,
                         std::move(init_pos));
}

WarehouseBotEnv::WarehouseBotEnv(Coord &&shape, std::unordered_set<Coord> walls,
                                 std::unordered_set<Coord> crates,
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
size_t WarehouseBotEnv::sum_gps() const {
  size_t sum = 0;
  for (const auto &crate : crates_)
    sum += gps_coordinate(crate);
  return sum;
}
