#include "math.h"

uint64_t gcd(uint64_t a, uint64_t b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

uint64_t lcd(uint64_t a, uint64_t b) { return (a * b) / gcd(a, b); }
