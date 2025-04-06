#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

void generateTestFile(const std::string &filename,
                      const std::vector<int> &data) {
  std::ofstream file(filename);
  file << data.size() << "\n";
  for (const auto &num : data) {
    file << num << " ";
  }
  file.close();
}

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 1000000000); // Range 1 to 1e9

  // Test 1: 1e8 numbers, random
  std::vector<int> test1(100000000);
  for (auto &num : test1) {
    num = dis(gen);
  }
  generateTestFile("big_tests/1-sortare.in", test1);

  // Test 2: 1e7 numbers <= 1e9, almost sorted with random swaps
  std::vector<int> test2(10000000);
  for (auto &num : test2) {
    num = std::min(1000000 - 1, dis(gen)); // Ensuring numbers are <= 1e6
  }
  std::sort(test2.begin(),
            test2.end()); // Partially sort the first 1000 elements

  // Perform 1000 random swaps
  std::uniform_int_distribution<> index_dis(0, test2.size() - 1);
  for (int i = 0; i < 1000; ++i) {
    int idx1 = index_dis(gen);
    int idx2 = index_dis(gen);
    std::swap(test2[idx1], test2[idx2]);
  }

  generateTestFile("big_tests/2-sortare.in", test2);

  // Test 3: 1e7 numbers <= 1e9, in descending order
  std::vector<int> test3(10000000);
  for (auto &num : test3) {
    num = dis(gen);
  }
  std::sort(test3.rbegin(), test3.rend());
  generateTestFile("big_tests/3-sortare.in", test3);

  // Test 4: 1e7 numbers, sorted
  std::vector<int> test4(10000000);
  for (auto &num : test4) {
    num = dis(gen);
  }
  std::sort(test4.begin(), test4.end());
  generateTestFile("big_tests/4-sortare.in", test4);

  // Test 5: 1e7 numbers, all equal to 1
  std::vector<int> test5(10000000, 1);
  generateTestFile("big_tests/5-sortare.in", test5);

  return 0;
}
