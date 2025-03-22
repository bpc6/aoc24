#ifndef AOC24_DAY15_H
#define AOC24_DAY15_H

#include <Eigen/Dense>
#include <string>
#include <unordered_map>

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

class WarehouseBotEnv {
public:
  WarehouseBotEnv(Coord shape, std::initializer_list<Coord> walls,
                  std::initializer_list<Coord> crates, Coord init_pos);
  std::string to_string();

private:
  enum Content { WALL, CRATE };
  char to_char_(WarehouseBotEnv::Content cont);
  Coord shape_;
  Coord pos_;
  std::unordered_map<Coord, Content> map_{};
};

#endif // AOC24_DAY15_H
