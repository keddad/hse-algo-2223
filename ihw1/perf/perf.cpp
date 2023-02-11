#include <chrono>
#include <iostream>

#include "perf.h"

bool is_sorted(std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < v[i - 1])
        {
            return false;
        }
    }

    return true;
}

// Returns average ns and operation amount
std::pair<long long, long long> speedtest(std::function<int(std::vector<int> &)> f, std::vector<int> &v)
{
    long long time = 0;
    long long op_count = 0;

    for (int i = 0; i < retries; i++)
    {
        std::vector<int> to_sort(v.begin(), v.end());

        auto t1 = std::chrono::high_resolution_clock::now();
        op_count = f(to_sort);
        auto t2 = std::chrono::high_resolution_clock::now();

        time += std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

        if (!is_sorted(to_sort))
        {
            std::cerr << "Array wasn't sorted properly!";
            return std::make_pair(-1, -1);
        }
    }

    return std::make_pair(time / retries, op_count);
}

std::vector<int> smallSizes() {
    std::vector<int> v;

    for (int i = 50; i <= 300; i += 50)
    {
        v.push_back(i);
    }
    
    return v;
};

std::vector<int> bigSizes() {
    std::vector<int> v;

    for (int i = 100; i <= 4100; i += 100)
    {
        v.push_back(i);
    }
    
    return v;
};