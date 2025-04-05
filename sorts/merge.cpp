#include "sortari.h"

void merge(std::vector<int> &v, int l, int mid, int r) {
  std::vector<int> aux;
  int i = l, j = mid + 1;

  while (i <= mid and j <= r) {
    if (v[i] < v[j]) {
      aux.push_back(v[i]);
      i++;
    } else {
      aux.push_back(v[j]);
      j++;
    }
  }
  while (i <= mid) {
    aux.push_back(v[i]);
    i++;
  }
  while (j <= r) {
    aux.push_back(v[j]);
    j++;
  }

  for (int i = l; i <= r; i++) {
    v[i] = aux[i - l];
  }
}