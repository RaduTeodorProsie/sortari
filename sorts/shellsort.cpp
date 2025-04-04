#include "sortari.h"

std::vector<int> generateSedgewickGaps(int max_size)
{
    std::vector<int> ans;

    for (int i = 0; 1; i++)
    {
        int gap;
        if ((i & 1))
            gap = 8 * (1 << i) - 6 * (1 << ((i + 1) / 2)) + 1;
        else
            gap = 9 * (1 << i) - 9 * (1 << (i / 2)) + 1;

        if (gap >= max_size)
            break;
        ans.push_back(gap);
    }
    
    int size = ans.size();
    for(int i=0;i<(size-1)/2;i++)
        std::swap( ans[i],ans[size-1-i] );

    return ans;
}

void shellsort(std::vector<int>& v)
{
    int size = v.size(), j;
    std::vector<int> gaps = generateSedgewickGaps(size);

    for (auto gap : gaps)
    {
        for (int i = gap; i < size; i++)
        {
            int aux = v[i];
            for (j = i; j >= gap and v[j - gap] > aux; j -= gap)
                v[j] = v[j - gap];
            v[j] = aux;
        }
    }
}