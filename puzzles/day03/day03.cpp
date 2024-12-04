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

long part2(const std::string &filename) { return part1(filename); }
