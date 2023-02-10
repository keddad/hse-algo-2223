#include "sorts.h"

#include <utility>

int partition(std::vector<int> &v, int low, int high, int *operations)
{
    int pivot = v[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        (*operations)++;
        if (v[j] <= pivot)
        {
            i++;
            std::swap(v[i], v[j]);
            (*operations)++;
        }
    }

    std::swap(v[i + 1], v[high]);
    (*operations)++;
    return i + 1;
}

void internalQuickSort(std::vector<int> &v, int low, int high, int *operations)
{
    if (low < high)
    {
        int pi = partition(v, low, high, operations);
        (*operations)++;

        internalQuickSort(v, low, pi - 1, operations);
        internalQuickSort(v, pi + 1, high, operations);
    }
}

int quickSort(std::vector<int> &v)
{
    int operations = 0;
    internalQuickSort(v, 0, v.size(), &operations);

    return operations;
};
