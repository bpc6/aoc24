#include "day09.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::vector<size_t> compress_disc(const std::string &discmap) {
  auto back_fid = discmap.size() / 2;
  auto back_it = discmap.rbegin();

  size_t front_fid = 0;
  bool front_is_file = true;
  auto front_it = discmap.begin();

  auto back_remaining = *back_it - '0';
  auto front_remaining = *front_it - '0';
  std::vector<size_t> result{};
  while (back_fid > front_fid) {

    if (front_is_file) {
      std::ranges::copy(std::vector<size_t>(front_remaining, front_fid),
                        std::back_inserter(result));
      front_it += 1;
      front_remaining = *front_it - '0';
      front_is_file = false;
    } else if (front_remaining < back_remaining) {
      std::ranges::copy(std::vector<size_t>(front_remaining, back_fid),
                        std::back_inserter(result));
      back_remaining -= front_remaining;
      front_it += 1;
      front_remaining = *front_it - '0';
      front_fid += 1;
      front_is_file = true;
    } else if (back_remaining < front_remaining) {
      std::ranges::copy(std::vector<size_t>(back_remaining, back_fid),
                        std::back_inserter(result));
      front_remaining -= back_remaining;
      back_it += 2;
      back_remaining = *back_it - '0';
      back_fid -= 1;
    } else {
      std::ranges::copy(std::vector<size_t>(back_remaining, back_fid),
                        std::back_inserter(result));
      back_it += 2;
      back_remaining = *back_it - '0';
      back_fid -= 1;

      front_it += 1;
      front_remaining = *front_it - '0';
      front_fid += 1;
      front_is_file = true;
    }
  }

  if (front_is_file) {
    std::ranges::copy(std::vector<size_t>(back_remaining, back_fid),
                      std::back_inserter(result));
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
  return calc_checksum(compress_disc(readLines(PARENT_DIR "/" + filename)[0]));
}

size_t part2(const std::string &filename) { return 0; }
