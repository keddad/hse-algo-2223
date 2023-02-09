#include "sorts.h"

int simpleInsertSort(std::vector<int> &v)
{
    int actions = 0;

    for (int step = 1; step < v.size(); step++)
    {
        int key = v[step];
        int j = step - 1;

        while (key < v[j] && j >= 0)
        {
            actions += 2;
            v[j + 1] = v[j];
            --j;
        }
        actions++;
        v[j + 1] = key;
    }

    return actions;
}

int binarySearch(std::vector<int> &v, int item,
                 int low, int high, int *actions)
{
    if (high <= low)
    {
        (*actions) += 2;
        return (item > v[low]) ? (low + 1) : low;
    }

    int mid = (low + high) / 2;

    if (item == v[mid])
    {
        (*actions) += 2;
        return mid + 1;
    }

    (*actions) += 1;
    if (item > v[mid])
    {
        return binarySearch(v, item, mid + 1, high, actions);
    }
    return binarySearch(v, item, low, mid - 1, actions);
}

int binaryInsertSort(std::vector<int> &v)
{
    int actions = 0;

    for (int i = 1; i < v.size(); ++i)
    {
        int j = i - 1;
        int selected = v[i];

        int loc = binarySearch(v, selected, 0, j, &actions);

        while (j >= loc)
        {
            v[j + 1] = v[j];
            j--;
            actions++;
        }
        v[j + 1] = selected;
        actions++;
    }

    return actions;
}