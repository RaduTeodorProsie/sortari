#include "sortari.h"

void merge(std::vector<int> &v, int l, int mid, int r);

void apply_mergesort(std::vector<int> &v, int l, int r) {
  if (l == r)
    return;

  int mid = (l + r) / 2;

  apply_mergesort(v, l, mid);
  apply_mergesort(v, mid + 1, r);

  merge(v, l, mid, r);
}

void mergesort(std::vector<int> &v) { apply_mergesort(v, 0, v.size() - 1); }
