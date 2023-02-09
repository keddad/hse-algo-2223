#include "sorts.h"

#include <algorithm>

void radixHelper(std::vector<int> &v, int place, int *operations)
{
    std::vector<int> output(v.size());
    int count[10] = {};

    *operations += v.size();
    for (int i = 0; i < v.size(); i++)
    {
        count[(v[i] / place) % 10]++;
    }

    *operations += 10;
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    *operations += v.size() * 2;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        output[count[(v[i] / place) % 10] - 1] = v[i];
        count[(v[i] / place) % 10]--;
    }

    *operations += v.size();
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = output[i];
    }
}

int radixSort(std::vector<int> &v)
{
    if (v.size() == 0) {
        return 0;
    }

    int m = *std::max_element(v.begin(), v.end());
    int operations = 0;

    for (int place = 1; m / place > 0; place *= 10)
    {
        radixHelper(v, place, &operations);
    }

    return operations;
};
