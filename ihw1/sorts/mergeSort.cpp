#include "sorts.h"

void merge(std::vector<int> &v, int l, int r, int split, int *operations)
{
    std::vector<int> tmp_left(split - l + 1);
    std::vector<int> tmp_right(r - split);

    (*operations) += r - l + 1;

    for (int i = 0; i < split - l + 1; ++i)
    {
        tmp_left[i] = v[l + i];
    }

    for (int i = 0; i < r - split; ++i)
    {
        tmp_right[i] = v[split + i + 1];
    }

    int i = 0, j = 0, cur = l;

    while (i < split - l + 1 && j < r - split)
    {
        if (tmp_left[i] <= tmp_right[j])
        {
            v[cur] = tmp_left[i];
            i++;
        }
        else
        {
            v[cur] = tmp_right[j];
            j++;
        }
        cur++;
        (*operations)++;
    }

    while (i < split - l + 1)
    {
        v[cur] = tmp_left[i];
        i++;
        cur++;
        (*operations)++;
    }

    while (j < r - split)
    {
        v[cur] = tmp_right[j];
        j++;
        cur++;
        (*operations)++;
    }
}

void internalMergeSort(std::vector<int> &v, int l, int r, int *operations)
{
    if (l >= r)
    {
        return;
    }

    int split = l + (r - l) / 2;

    internalMergeSort(v, l, split, operations);
    internalMergeSort(v, split + 1, r, operations);

    merge(v, l, r, split, operations);
}

int mergeSort(std::vector<int> &v)
{
    int operations = 0;

    internalMergeSort(v, 0, v.size() - 1, &operations);

    return operations;
};
