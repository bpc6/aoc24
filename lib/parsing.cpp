#include "parsing.h"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <sstream>

std::string readFile(const std::string &file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening the file.");
  }
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

std::vector<std::string> readLines(const std::string &file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening the file" + file_path);
  }

  std::vector<std::string> lines;
  std::string line;

  while (std::getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

std::vector<std::vector<char>> readCharMatrix(const std::string &file_path) {
  std::ifstream file(file_path);
  if (!file.is_open()) {
    throw std::runtime_error("Error opening the file.");
  }

  std::vector<std::vector<char>> mat;
  std::string line;

  while (std::getline(file, line)) {
    mat.emplace_back(line.begin(), line.end());
  }
  file.close();
  return mat;
}

std::vector<std::vector<int>> readIntMatrix(const std::string &file_path) {
  auto char_matrix = readCharMatrix(file_path);
  std::vector<std::vector<int>> int_matrix;
  int_matrix.reserve(char_matrix.size());

  std::ranges::transform(
      char_matrix, std::back_inserter(int_matrix), [](const auto &row) {
        std::vector<int> int_row;
        int_row.reserve(row.size());
        std::ranges::transform(row, std::back_inserter(int_row),
                               [](char c) { return c - '0'; });
        return int_row;
      });
  return int_matrix;
}

bool all_digits(const std::string &s) {
  return std::ranges::all_of(s, [](unsigned char c) { return isdigit(c); });
}

std::vector<int> ints(const std::vector<std::string> &strings) {
  std::vector<int> ret;
  for (const auto &word : strings) {
    if (!word.empty() && (word[0] == '-' || all_digits(word))) {
      ret.push_back(stoi(word));
    } else {
      throw std::invalid_argument(word + " is invalid");
    }
  }
  return ret;
}

std::vector<int> ints(const std::string &s) { return ints(split(s)); }

std::vector<int> ints(const std::string &s, char sep) {
  return ints(split(s, sep));
}

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> result;
  std::stringstream ss(s);
  std::string item;

  while (getline(ss, item, delim)) {
    result.push_back(item);
  }
  return result;
}

std::vector<std::string> split(const std::string &s,
                               const std::string &delimiter) {
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  std::string token;
  std::vector<std::string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
    res.push_back(token);
  }

  res.push_back(s.substr(pos_start));
  return res;
}

std::vector<std::string> split(std::string const &input) {
  std::istringstream buffer(input);
  std::vector<std::string> ret((std::istream_iterator<std::string>(buffer)),
                               std::istream_iterator<std::string>());
  return ret;
}

std::string join(const std::vector<std::string> &v, char c) {
  std::string s;
  for (auto p = v.begin(); p != v.end(); ++p) {
    s += *p;
    if (p != v.end() - 1)
      s += c;
  }
  return s;
}

std::string join(const std::vector<std::string> &v) {
  std::string s;
  for (const auto &p : v) {
    s += p;
  }
  return s;
}
