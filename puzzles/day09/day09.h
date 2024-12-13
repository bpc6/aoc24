#ifndef AOC24_DAY01_H
#define AOC24_DAY01_H

#include <string>
#include <vector>

std::vector<size_t> compress_disc(const std::string &discmap);
std::vector<size_t> compress_disc_whole_files(const std::string &discmap);
size_t calc_checksum(const std::vector<size_t> &compressed);

size_t part1(const std::string &filename);
size_t part2(const std::string &filename);

#endif // AOC24_DAY01_H
