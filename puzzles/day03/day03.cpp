#include "day03.h"
#include "parsing.h"
#include <regex>

long part1(const std::string &filename) {
  auto txt = readFile(PARENT_DIR "/" + filename);

  const std::regex re(R"(mul\((-?\d+),(-?\d+)\))");
  std::smatch match;

  int tot = 0;
  for (std::sregex_iterator it(txt.begin(), txt.end(), re), end; it != end;
       ++it) {
    tot += stoi((*it)[1]) * stoi((*it)[2]);
  }

  return tot;
}

long part2(const std::string &filename) { return 0; }
