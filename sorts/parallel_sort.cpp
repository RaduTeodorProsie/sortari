#include "sortari.h"
#include <algorithm>
#include <execution>
#include <vector>

void parallel_sort(std::vector<int> &v) {
  std::sort(std::execution::par, v.begin(), v.end());
}
