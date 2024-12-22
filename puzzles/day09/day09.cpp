#include "day09.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

void advance_back(auto &back_it, int &back_remaining, size_t &back_fid) {
  back_it += 2;
  back_remaining = *back_it - '0';
  back_fid -= 1;
}

void advance_front(auto &front_it, int &front_remaining, size_t &front_fid) {
  front_it += 1;
  front_remaining = *front_it - '0';
  front_fid += 1;
}

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
      advance_front(front_it, front_remaining, front_fid);
      front_is_file = true;
    } else if (back_remaining < front_remaining) {
      std::ranges::copy(std::vector<size_t>(back_remaining, back_fid),
                        std::back_inserter(result));
      front_remaining -= back_remaining;
      advance_back(back_it, back_remaining, back_fid);
    } else {
      std::ranges::copy(std::vector<size_t>(back_remaining, back_fid),
                        std::back_inserter(result));
      advance_back(back_it, back_remaining, back_fid);
      advance_front(front_it, front_remaining, front_fid);
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

struct file {
  size_t id;
  int size;
  size_t loc;

  [[nodiscard]] size_t checksum() const {
    return id * std::ranges::fold_left(std::views::iota(loc, loc + size), 0,
                                       std::plus<>{});
  };
};

struct space {
  int size;
  size_t loc;
};

std::pair<std::vector<file>, std::vector<space>>
every_other(const std::string &intseq) {
  std::vector<file> left;
  std::vector<space> right;
  size_t curr_loc{0};
  for (auto [idx, c] : std::views::enumerate(intseq)) {
    if (idx % 2 == 0) {
      left.push_back(file(idx / 2, c - '0', curr_loc));
    } else {
      right.push_back(space(c - '0', curr_loc));
    }
    curr_loc += c - '0';
  }
  return {left, right};
}

size_t compress_disc_whole_files(const std::string &discmap) {
  auto [files, spaces] = every_other(discmap);
  std::ranges::reverse(files);
  for (auto &file : files) {
    for (auto &space : spaces) {
      if (file.size <= space.size) {
        file.loc = space.loc;
        space.size -= file.size;
        space.loc += file.size;
        break;
      }
    }
  }

  std::ranges::sort(files, [](file f1, file f2) { return f1.loc < f2.loc; });
  size_t result = 0;
  for (const auto &f : files) {
    result += f.checksum();
  }
  return result;
}

size_t part2(const std::string &filename) {
  return compress_disc_whole_files(readLines(PARENT_DIR "/" + filename)[0]);
}
