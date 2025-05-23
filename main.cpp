#include "sorts/sortari.h"
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>
const std::string path = "../big_tests/";

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  std::vector<int> v, cop;
  for (int i = 1; i <= 5; i++) {
    const std::string to_open = path + std::to_string(i) + "-sortare.in";
    freopen(to_open.c_str(), "r", stdin);
    std::cout << "TESTUL " << std::to_string(i) << "\n";
    std::cin >> n;
    v.resize(n);
    for (int j = 0; j < n; j++)
      std::cin >> v[j];
    auto start = std::chrono::high_resolution_clock::now();
    auto end = start;
    auto elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "radixsort: ";
    radixsort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "stl_sort: ";
    stl_sort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "shellsort: ";
    shellsort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "heapsort: ";
    heapsort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "mergesort: ";
    mergesort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "timsort: ";
    timsort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "parallel sort: ";
    parallel_sort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
              << " seconds\n";
    assert(is_sorted(cop.begin(), cop.end()));

    cop = v;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "counting_sort: ";
    counting_sort(cop);
    end = std::chrono::high_resolution_clock::now();
    elapsed =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    if (is_sorted(cop.begin(), cop.end()))
      std::cout << std::setprecision(4) << 1.0 * elapsed.count() / 1000
                << " seconds\n";
    else
      std::cout << "nu poate sorta\n";

    std::cout << '\n';
  }
}
