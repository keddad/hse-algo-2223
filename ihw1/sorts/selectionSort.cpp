#include "sorts.h"

#include <utility>

int selectionSort(std::vector<int> &v)
{
    int actions = 0;

    int min_idx;
    for (int i = 0; i < v.size() - 1; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            actions++;
            if (v[j] < v[min_idx])
            {
                actions++;
                min_idx = j;
            }
        }

        actions++;
        if (min_idx != i)
        {
            actions++;
            std::swap(v[min_idx], v[i]);
        }
    }

    return actions;
}