#include "sortari.h"
void radixsort(std::vector<int> &v) {
  const int B = 8;
  const int BITS = 32;
  std::vector<int> b(BITS, 0);

  int m = 1, n = v.size();
  b[0] = 1;
  for (int i = 1; i < 31; i++)
    b[i] = (b[i - 1] | (1 << i));
  for (int i = 0; (i + 1) * B <= BITS; i++) {
    std::vector<int> f[1 << B];
    for (int j = 0; j < n; j++) {
      m = (v[j] >> (i * B));
      m &= b[B - 1];
      f[m].emplace_back(v[j]);
    }

    int now = 0;
    for (int j = 0; j < (const int)(1 << B); j++)
      for (auto &it : f[j])
        v[now++] = it;
  }
}
