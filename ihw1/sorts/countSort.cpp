#include "sorts.h"
#include <algorithm>

int countSort(std::vector<int> &v)
{
    int operations = 0;

    int min_val = *std::min_element(v.begin(), v.end());
    int max_val = *std::max_element(v.begin(), v.end());

    operations += v.size() * 2; // min/max search linear

    std::vector<int> table(max_val - min_val + 1, 0);

    for (int i = 0; i < v.size(); i++)
    {
        table[v[i] - min_val]++;
    }

    operations += v.size();

    int ptr = 0;

    for (int i = 0; i < table.size(); i++)
    {
        while (table[i])
        {
            v[ptr] = i + min_val;
            table[i]--;
            ptr++;
            operations++;
        }
    }

    return operations;
};
