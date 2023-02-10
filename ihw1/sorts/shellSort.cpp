#include "sorts.h"

// a bit of copypaste hurts no one

int shellCiurSort(std::vector<int> &v)
{
    int operations = 0;

    std::vector<int> ciur = {701, 301, 132, 57, 23, 10, 4, 1};

    for (int interval_i = 0; interval_i < ciur.size(); ++interval_i)
    {
        int interval = ciur[interval_i];

        for (int i = interval; i < v.size(); i += 1)
        {
            operations++;
            int temp = v[i];
            int j;
            for (j = i; j >= interval && v[j - interval] > temp; j -= interval)
            {
                operations++;
                v[j] = v[j - interval];
            }
            operations++;
            v[j] = temp;
        }
    }

    return operations;
};

int shellShellSort(std::vector<int> &v)
{
    int operations = 0;

    for (int interval = v.size() / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < v.size(); i += 1)
        {
            operations++;
            int temp = v[i];
            int j;
            for (j = i; j >= interval && v[j - interval] > temp; j -= interval)
            {
                operations++;
                v[j] = v[j - interval];
            }
            operations++;
            v[j] = temp;
        }

    }

    return operations;
};