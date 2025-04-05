#include "sortari.h"
#include <algorithm>

void mergesort(std::vector<int> &v, int l, int r) {
  if (l == r)
    return;

  int mid = (l + r) / 2;

  mergesort(v, l, mid);
  mergesort(v, mid + 1, r);

  std::merge(v.begin() + l, v.begin() + mid + 1, v.begin() + mid + 1,
             v.begin() + r + 1, v.begin() + l);
}

void mergesort(std::vector<int> &v) { mergesort(v, 0, v.size() - 1); }
