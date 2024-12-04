#include "day03.h"
#include "parsing.h"
#include <algorithm>
#include <regex>

long part1(const std::string &filename) {
  auto txt = readFile(PARENT_DIR "/" + filename);

  const std::regex mul(R"(mul\((-?\d+),(-?\d+)\))");

  int tot = 0;
  for (std::sregex_iterator it(txt.begin(), txt.end(), mul), end; it != end;
       ++it) {
    const auto &match = *it;
    tot += stoi(match[1]) * stoi(match[2]);
  }

  return tot;
}

std::vector<size_t> find_regex_inds(const std::string &s,
                                    const std::regex &re) {
  std::vector<std::size_t> result;
  for (std::sregex_iterator it(s.begin(), s.end(), re), end; it != end; ++it) {
    result.push_back(it->position());
  }
  return result;
}

std::optional<int> leftmost_index(const std::vector<size_t> &inds,
                                  long left_of) {
  std::vector<size_t> inds_desc(inds.size());
  std::ranges::copy(inds, inds_desc.begin());
  std::ranges::sort(inds_desc, std::greater<>());

  for (auto idx : inds_desc) {
    if (idx < left_of) {
      return idx;
    }
  }
  return {};
}

bool do_active(const std::string &s, long idx) {
  auto left_do =
      leftmost_index(find_regex_inds(s, std::regex(R"(do\(\))")), idx);
  auto left_dont =
      leftmost_index(find_regex_inds(s, std::regex(R"(don't\(\))")), idx);

  if (left_dont) {
    if (left_do) {
      return left_do > left_dont;
    }
    return false;
  }
  return true;
}

long part2(const std::string &filename) {
  auto txt = readFile(PARENT_DIR "/" + filename);

  const std::regex mul(R"(mul\((-?\d+),(-?\d+)\))");

  int tot = 0;
  for (std::sregex_iterator it(txt.begin(), txt.end(), mul), end; it != end;
       ++it) {
    const auto &match = *it;
    if (do_active(txt, match.position())) {
      tot += stoi(match[1]) * stoi(match[2]);
    }
  }

  return tot;
}
