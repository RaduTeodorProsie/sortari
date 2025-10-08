#include "sorts/sortari.h"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
const std::string path = "../big_tests/";

template <typename Fn>
void test_sort(const char *name, Fn &&fn, const std::vector<int> &v) {
  std::vector<int> cop = v;
  auto start = std::chrono::high_resolution_clock::now();
  std::cout << name << ": ";
  std::forward<Fn>(fn)(cop);
  auto end = std::chrono::high_resolution_clock::now();
  auto elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
            << " seconds\n";
  assert(is_sorted(cop.begin(), cop.end()));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::vector<int> v;
  for (int i = 1; i <= 5; i++) {
    const std::string to_open = path + std::to_string(i) + "-sortare.in";
    freopen(to_open.c_str(), "r", stdin);
    std::cout << "TESTUL " << std::to_string(i) << "\n";
    std::cin >> n;
    v.resize(n);
    for (int j = 0; j < n; j++)
      std::cin >> v[j];

    // Use one helper for all sorts; counting_sort removed per request
    test_sort("radixsort", radixsort, v);
    test_sort("stl_sort", stl_sort, v);
    test_sort("shellsort", shellsort, v);
    test_sort("heapsort", heapsort, v);
    test_sort("mergesort", mergesort, v);
    test_sort("timsort", timsort, v);
    test_sort("parallel sort", parallel_sort, v);

    std::cout << '\n';
  }
}
