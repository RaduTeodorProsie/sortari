#pragma once
#include <vector>

void radixsort(std::vector<int> &v);

void stl_sort(std::vector<int> &v);

void shellsort(std::vector<int> &v);

void mergesort(std::vector<int> &v);

void heapsort(std::vector<int> &v);

void timsort(std::vector<int> &v);

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