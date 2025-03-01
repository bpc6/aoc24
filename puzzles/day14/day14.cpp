#include "day14.h"
#include "parsing.h"

size_t part1(const std::string &filename, int width, int height) { return 0; }

size_t part2(const std::string &filename, int width, int height) { return 0; }

BotEnv::BotEnv(int width, int height, Vec pos, Vec velo)
    : width_(width), height_(height), pos_(pos), velo_(velo) {}

void BotEnv::step() { pos_ += velo_; }

Vec BotEnv::pos() const { return pos_; }
