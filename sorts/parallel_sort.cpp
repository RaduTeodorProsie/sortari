#include "sortari.h"
#include <algorithm>
#include <vector>
#include <execution>

void parallel_sort(std::vector<int> &v){
    std::sort(std::execution::par, v.begin(), v.end()); 
}
