#include "day09.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::vector<size_t> compress_disc(const std::string &discmap) {
  auto back_fid = discmap.size() / 2;
  bool back_is_file = discmap.size() % 2;
  auto back_it = discmap.rbegin();

  size_t front_fid = 0;
  bool front_is_file = true;
  auto front_it = discmap.begin();

  auto back_remaining = *back_it - '0';
  std::vector<size_t> result{};
  while (front_it <= back_it.base()) {
    auto tmp = front_it == back_it.base();
    auto front_remaining = *front_it - '0';

    if (front_is_file && (back_fid > front_fid)) {
      std::ranges::copy(std::vector<size_t>(front_remaining, front_fid),
                        std::back_inserter(result));
      front_it += 1;
      front_fid += 1;
    } else {
      if (!back_is_file) {
        ++back_it;
        back_is_file = !back_is_file;
      }
      while (front_remaining > 0 && back_fid >= front_fid) {
        if (back_remaining == 0) {
          back_it += 2;
          back_remaining = *back_it - '0';
          back_fid -= 1;
        } else {
          result.push_back(back_fid);
          front_remaining -= 1;
          back_remaining -= 1;
        }
      }
      front_it += 1;
    }
    front_is_file = !front_is_file;
  }

  return result;
}

size_t calc_checksum(const std::vector<size_t> &compressed) {
  size_t result{};
  for (const auto [idx, val] : std::views::enumerate(compressed)) {
    result += idx * val;
  }
  return result;
}

size_t part1(const std::string &filename) {
  return calc_checksum(compress_disc(readFile(PARENT_DIR "/" + filename)));
}

size_t part2(const std::string &filename) { return 0; }
