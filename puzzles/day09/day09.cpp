#include "day09.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>


bool back_behind_front(size_t back_fid, size_t front_fid) { return back_fid >= front_fid; }

void move_back_to_first_available(size_t back_fid, std::vector<size_t> &result, int &back_remaining,
                                  int &front_remaining) {
  result.push_back(back_fid);
  front_remaining -= 1;
  back_remaining -= 1;
}

void skip_to_next_file(size_t &back_fid,
                       std::basic_string<char, std::char_traits<char>, std::allocator<char>>::const_reverse_iterator &back_it,
                       int &back_remaining) {
  back_it += 2;
  back_remaining = *back_it - '0';
  back_fid -= 1;
}

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
    auto front_remaining = *front_it - '0';

    if (front_is_file && (back_fid > front_fid)) {
      std::ranges::copy(std::vector<size_t>(front_remaining, front_fid),
                        std::back_inserter(result));
      front_fid += 1;
    } else {
      if (!back_is_file) {
        ++back_it;
        back_is_file = !back_is_file;
      }
      while ((front_remaining > 0) && back_behind_front(back_fid, front_fid)) {
        if (back_remaining == 0) {
          skip_to_next_file(back_fid, back_it, back_remaining);
        } else {
          move_back_to_first_available(back_fid, result, back_remaining, front_remaining);
        }
      }
    }
    front_it += 1;
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
  return calc_checksum(compress_disc(readLines(PARENT_DIR "/" + filename)[0]));
}

size_t part2(const std::string &filename) { return 0; }
