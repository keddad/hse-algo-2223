#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <vector>

#include "sorts/sorts.h"

std::map<std::string, std::function<int(std::vector<int> &)>> sorts{
    {"selectionSort", selectionSort},
    {"bubbleSort", bubbleSort},
    {"bubbleSortA", bubbleSortA},
    {"bubbleSortAB", bubbleSortAB},
    {"simpleInsertSort", simpleInsertSort},
    {"binaryInsertSort", binaryInsertSort},
    {"countSort", countSort},
    {"radixSort", radixSort},
    {"mergeSort", mergeSort},
    {"quickSort", quickSort},
    {"heapSort", heapSort},
    {"shellShellSort", shellShellSort},
    {"shellCiurSort", shellCiurSort},
};

int main(int argc, char *argv[])
{
    if (sorts.find(argv[1]) == sorts.end())
    {
        std::cerr << "No such sort!\n";
        return 1;
    }

    auto sort_function = sorts[argv[1]];

    std::vector<int> v = {4, 2, 1, 2, 3, 6, 5, 4, 19, 0};
    int op = sort_function(v);

    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }

    std::cout << "\n"
              << op << "\n";
}