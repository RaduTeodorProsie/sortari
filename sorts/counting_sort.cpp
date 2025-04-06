#include "sortari.h"
#include <algorithm>
#include <vector>

void counting_sort(std::vector<int> &v) {
  const int lim = 1e6;
  std::vector<int> f(lim, 0);
  for (int x : v)
    if (x < lim)
      f[x]++;
    else
      return;

  for (int i = 0, idx = 0; i < lim; i++)
    while (f[i]--)
      v[idx++] = i;
}
