#include "sorts.h"

#include <utility>

void heapify(std::vector<int> &v, int n, int i, int *operations)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    (*operations)++;
    if (left < n && v[left] > v[largest])
        largest = left;

    (*operations)++;
    if (right < n && v[right] > v[largest])
        largest = right;

    (*operations)++;
    if (largest != i)
    {   
        (*operations)++;
        std::swap(v[i], v[largest]);
        heapify(v, n, largest, operations);
    }
}

int heapSort(std::vector<int> &v)
{
    int operations = 0;

    for (int i = v.size() / 2 - 1; i >= 0; i--)
    {
        heapify(v, v.size(), i, &operations);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        std::swap(v[0], v[i]);
        heapify(v, i, 0, &operations);
    }

    return operations;
};