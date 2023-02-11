#include <random>
#include <algorithm>

#include "gen.h"

std::vector<int> getRandom(int size, int min, int max)
{
    std::vector<int> v(size);

    std::random_device rd;                           
    std::mt19937 rng(rd());                          
    std::uniform_int_distribution<int> uni(min, max);

    for (int i = 0; i < size; i++)
    {
        v[i] = uni(rng);
    }

    return v;
}

std::vector<int> getAlmosrtSorted(int size, int min, int max) {
    std::vector<int> v = getRandom(size, min, max);
    std::sort(v.begin(), v.end());

    std::random_device rd;                           
    std::mt19937 rng(rd());                          
    std::uniform_int_distribution<int> uni(0, v.size() - 1);

    for (int i = 0; i < almostSortedSwaps; i++)
    {
        int a = uni(rng), b = uni(rng);
        std::swap(v[a], v[b]);
    }
    
    return v;
}

std::vector<int> getReverseSorted(int size, int min, int max) {
    std::vector<int> v = getRandom(size, min, max);
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());

    return v;
};