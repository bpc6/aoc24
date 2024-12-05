#include "day05.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::vector<std::pair<int, int>> read_rules(const std::vector<std::string> &lines) {
    auto has_pipe = [](const std::string &s) {return s.find('|') != std::string::npos;};
    auto make_pair = [](const std::string &s) {return std::make_pair(std::stoi(s.substr(0, 2)), std::stoi(s.substr(3, 5)));};
    auto pairs = lines | std::views::filter(has_pipe) | std::views::transform(make_pair);
    return {pairs.begin(), pairs.end()};
}

std::vector<std::vector<int>> read_page_updates(const std::vector<std::string> &lines) {
    auto has_comma = [](const std::string &s) {return s.find(',') != std::string::npos;};
    auto to_ints = [](const std::string &s) {return ints(s, ',');};
    auto int_vecs = lines | std::views::filter(has_comma) | std::views::transform(to_ints);
    return {int_vecs.begin(), int_vecs.end()};
}

long part1(const std::string &filename) {
  return 0;
}

long part2(const std::string &filename) {
  return 0;
}
