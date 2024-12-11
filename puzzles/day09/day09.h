#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <string>
#include <vector>

std::string compress_disc(const std::string &discmap);
long calc_checksum(const std::string &discmap);

long part1(const std::string &filename);
long part2(const std::string &filename);

#endif // AOC24_DAY01_H
