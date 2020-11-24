#ifndef ch5_1_h
#define ch5_1_h

#include <bits/stdc++.h>

// [Page 117]
//   RANDOM(a, b)
//   - Time: O(lg(a - b))

namespace CLRS {
namespace CH5 {
int RANDOM() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937_64 generator(seed);
  std::uniform_int_distribution<int> distribution(0, 1);
  return distribution(generator);
}

int random(int a, int b) {
  if (a == b)
    return a;
  double mid = (a + b) / 2;
  int r = RANDOM();
  if (r == 0)
    return random(a, (int)floor(mid));
  else
    return random((int)ceil(mid), b);
}
}  // namespace CH5
}  // namespace CLRS

#endif