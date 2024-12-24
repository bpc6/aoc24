#ifndef AOC24_BINARY_TREE_H
#define AOC24_BINARY_TREE_H
#include <cmath>
#include <memory>

unsigned long count_digits(unsigned long n) {
  if (n == 0)
    return 1;
  return static_cast<unsigned long>(std::log10(n)) + 1;
}

std::pair<unsigned long, unsigned long> split_digits(unsigned long n) {
  size_t half_digits = (static_cast<size_t>(std::log10(n)) + 1) / 2;
  auto divisor = static_cast<unsigned long>(std::pow(10, half_digits));
  return {n / divisor, n % divisor};
}

class BinaryTree {

  class Node {
    unsigned long contents_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;

  public:
    explicit Node(unsigned long contents, std::unique_ptr<Node> left = nullptr,
                  std::unique_ptr<Node> right = nullptr)
        : contents_(contents), left_(std::move(left)),
          right_(std::move(right)) {}
    [[nodiscard]] unsigned long get_contents() const { return contents_; }
    [[nodiscard]] bool has_left() const { return static_cast<bool>(left_); }
    [[nodiscard]] bool has_right() const { return static_cast<bool>(right_); }
    [[nodiscard]] bool is_leaf() const { return !has_left() && !has_right(); }
    [[nodiscard]] Node &left() const { return *left_; }
    [[nodiscard]] Node &right() const { return *right_; }
    void set_left(std::unique_ptr<Node> &&node) { left_ = std::move(node); }
    void set_right(std::unique_ptr<Node> &&node) { right_ = std::move(node); }

    void update() {
      if (contents_ == 0) {
        contents_ += 1;
      } else if (count_digits(contents_) % 2 == 0) {
        const auto [left, right] = split_digits(contents_);
        set_left(std::make_unique<Node>(left));
        set_right(std::make_unique<Node>(right));
      } else {
        contents_ *= 2024;
      }
    }
  };

  std::unique_ptr<Node> root = nullptr;

public:
  void insert(unsigned long n) {
    if (root == nullptr) {
      root = std::make_unique<Node>(n);
      return;
    }
    auto new_root = std::make_unique<Node>(0);
    new_root->set_left(std::move(root));
    new_root->set_right(std::make_unique<Node>(n));
    root = std::move(new_root);
  }

  [[nodiscard]] unsigned long count_leaves() const {
    return count_leaves_recursive(*root);
  }

  void update() { return update_recursive(*root); }

private:
  [[nodiscard]] unsigned long count_leaves_recursive(const Node &node) const {
    if (node.is_leaf()) {
      return 1;
    } else {
      return count_leaves_recursive(node.left()) +
             count_leaves_recursive(node.right());
    }
  }

  void update_recursive(Node &node) {
    if (node.is_leaf()) {
      node.update();
    } else {
      update_recursive(node.left());
      update_recursive(node.right());
    }
  }
};

#endif // AOC24_BINARY_TREE_H
