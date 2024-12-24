#include "day11.h"
#include "binary_tree.h"
#include "parsing.h"
#include <algorithm>
#include <ranges>

size_t part1(const std::string &filename) {
  BinaryTree tree{};
  for (const auto &n : ints(readFile(PARENT_DIR "/" + filename))) {
    tree.insert(n);
  }

  for (int i = 0; i < 25; ++i) {
    tree.update();
  }
  return tree.count_leaves();
}

size_t part2(const std::string &filename) { return 0; }
