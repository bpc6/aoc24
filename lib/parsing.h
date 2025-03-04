#ifndef AOC24_PARSING_H
#define AOC24_PARSING_H

#include <string>
#include <vector>

std::string readFile(const std::string &file_path);
std::vector<std::string> readLines(const std::string &file_path);
std::vector<std::vector<char>> readCharMatrix(const std::string &file_path);
std::vector<std::vector<int>> readIntMatrix(const std::string &file_path);
std::vector<int> ints(const std::string &s);
std::vector<int> ints(const std::string &s, char sep);
std::vector<std::string> split(const std::string &s, char delim);
std::vector<std::string> split(const std::string &s,
                               const std::string &delimiter);
std::vector<std::string> split(std::string const &input);
std::string join(const std::vector<std::string> &v, char c);
std::string join(const std::vector<std::string> &v);

#endif // AOC24_PARSING_H
