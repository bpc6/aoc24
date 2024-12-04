#include "day03.h"
#include "parsing.h"
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

std::vector<long> find_regex_inds(const std::string &s, const std::regex &re) {
  std::vector<long> result;
  for (std::sregex_iterator it(s.begin(), s.end(), re), end; it != end; ++it) {
    result.push_back(it->position());
  }
  return result;
}

bool do_active(const std::string &s, long idx) {
  auto do_inds = find_regex_inds(s, std::regex(R"(do\(\))"));
  auto dont_inds = find_regex_inds(s, std::regex(R"(don't())"));

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
