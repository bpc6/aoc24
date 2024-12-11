#include "day09.h"
#include "parsing.h"
#include <numeric>

std::string compress_disc(const std::string &discmap) { return ""; }

long calc_checksum(const std::string &discmap) { return 0; }

long part1(const std::string &filename) {
  return calc_checksum(PARENT_DIR "/" + filename);
}

long part2(const std::string &filename) { return 0; }
