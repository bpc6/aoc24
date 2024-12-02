#include "aocmath.h"
#include <numeric>

uint64_t gcd(uint64_t a, uint64_t b) { return std::gcd(a, b); }

uint64_t lcd(uint64_t a, uint64_t b) { return std::lcm(a, b); }
