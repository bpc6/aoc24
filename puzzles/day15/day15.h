#ifndef AOC24_DAY15_H
#define AOC24_DAY15_H

#include <Eigen/Dense>
#include <string>
#include <unordered_set>

using Coord = Eigen::Vector2i;
namespace std {
template <> struct hash<Eigen::Vector2i> {
  std::size_t operator()(const Eigen::Vector2i &v) const {
    return std::hash<int>()(v.x()) ^ (std::hash<int>()(v.y()) << 1);
  }
};
} // namespace std

size_t part1(const std::string &filename);
size_t part2(const std::string &filename);

int gps_coordinate(const Coord &c);
Coord from_char(char c);

class WarehouseBotEnv {
public:
  WarehouseBotEnv(Coord &&shape, std::unordered_set<Coord> walls,
                  std::unordered_set<Coord> crates, Coord &&init_pos);
  [[nodiscard]] std::string to_string() const;
  bool is_wall(const Coord &c) const;
  bool is_crate(const Coord &c) const;
  Coord get_pos() const;
  void set_pos(const Coord &c);
  void step(const Coord &dir);
  size_t sum_gps() const;

private:
  Coord shape_;
  Coord pos_;
  std::unordered_set<Coord> walls_{};
  std::unordered_set<Coord> crates_{};
  bool can_move_(const Coord &dir);
  void shift_crates_(const Coord &dir);
};

WarehouseBotEnv from_string(const std::string &s);
WarehouseBotEnv from_string_double(const std::string &s);

#endif // AOC24_DAY15_H
