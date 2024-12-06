#include "day05.h"
#include "parsing.h"
#include <algorithm>
#include <numeric>
#include <ranges>

std::map<int, std::vector<int>>
read_map(const std::vector<std::string> &lines) {
  auto has_pipe = [](const std::string &s) {
    return s.find('|') != std::string::npos;
  };
  auto make_pair = [](const std::string &s) {
    return std::make_pair(std::stoi(s.substr(0, 2)), std::stoi(s.substr(3, 5)));
  };

  std::map<int, std::vector<int>> map;
  for (const auto [left, right] : lines | std::views::filter(has_pipe) |
                                      std::views::transform(make_pair)) {
    if (!map.contains(left)) {
      map.insert({left, {}});
    }
    map[left].push_back(right);
  }
  return map;
}

std::vector<std::vector<int>>
read_page_updates(const std::vector<std::string> &lines) {
  auto has_comma = [](const std::string &s) {
    return s.find(',') != std::string::npos;
  };
  auto to_ints = [](const std::string &s) { return ints(s, ','); };
  auto int_vecs =
      lines | std::views::filter(has_comma) | std::views::transform(to_ints);
  return {int_vecs.begin(), int_vecs.end()};
}

bool correct_order(const std::vector<int> update,
                   std::map<int, std::vector<int>> rules) {
  for (auto [idx, left] : update | std::views::enumerate) {
    for (auto right : update | std::views::drop(idx + 1)) {
      if (std::ranges::find(rules[left], right) == rules[left].end()) {
        return false;
      }
    }
  }
  return true;
}

int middle(const std::vector<int> &v) {
  if (v.size() == 0) {
    return 0;
  }
  return v[static_cast<int>(v.size() / 2)];
}

long part1(const std::string &filename) {
  auto lines = readLines(PARENT_DIR "/" + filename);
  auto rules = read_map(lines);
  auto updates = read_page_updates(lines);

  auto correct_middles = updates |
                         std::views::filter([&rules](std::vector<int> v) {
                           return correct_order(v, rules);
                         }) |
                         std::views::transform(middle);
  return std::ranges::fold_left(correct_middles, 0, std::plus<int>());
}

long part2(const std::string &filename) { return 0; }
