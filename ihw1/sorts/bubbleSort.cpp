#include "sorts.h"
#include <utility>

int bubbleSort(std::vector<int> &v)
{
    int actions = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            actions++;
            if (v[j] > v[j + 1])
            {
                actions++;
                std::swap(v[j], v[j + 1]);
            }
        }
    }

    return actions;
};

int bubbleSortA(std::vector<int> &v)
{
    int actions = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        bool exchanes_happened = false;
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            actions++;
            if (v[j] > v[j + 1])
            {
                exchanes_happened = true;
                actions++;
                std::swap(v[j], v[j + 1]);
            }
        }

        if (!exchanes_happened)
        {
            break;
        }
    }

    return actions;
};

int bubbleSortAB(std::vector<int> &v)
{
    int actions = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        int last_exchange = 0;
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            actions++;
            if (v[j] > v[j + 1])
            {
                last_exchange = j;
                actions++;
                std::swap(v[j], v[j + 1]);
            }
        }

        if (last_exchange == 0)
        {
            break;
        }
    }

    return actions;
};