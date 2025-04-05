#include "sortari.h"

inline void max_heapify(int poz, std::vector<int> &v, int size) {
  int l = poz * 2 + 1, r = poz * 2 + 2, best = poz;

  if (l < size and v[l] > v[best])
    best = l;
  if (r < size and v[r] > v[best])
    best = r;

  if (poz != best) {
    std::swap(v[poz], v[best]);
    max_heapify(best, v, size);
  }
}

void max_heap(std::vector<int> &v) {
  int size = v.size();

  for (int i = size / 2 - 1; i >= 0; i--)
    max_heapify(i, v, size);
}

void heapsort(std::vector<int> &v) {
  max_heap(v);

  for (int i = v.size(); i >= 2; i--) {
    std::swap(v[i - 1], v[0]);
    max_heapify(0, v, i - 1);
  }
}
