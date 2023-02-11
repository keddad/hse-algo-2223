#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <vector>

#include "sorts/sorts.h"
#include "perf/perf.h"
#include "perf/gen.h"

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

std::map<std::string, std::vector<int>> sizes_list{
    {"smallSizes", smallSizes()},
    {"bigSizes", bigSizes()},
};

int main(int argc, char *argv[])
{
    std::map<std::string, std::vector<int>> arrays {
        {"random0_5", getRandom(4101, 0, 5)},
        {"random0_4000", getRandom(4101, 0, 4000)},
        {"almost0_4000", getAlmosrtSorted(4101, 0, 4000)},
        {"reverse4100_1", getReverseSorted(4101, 1, 4100)},
    };

    for(auto sort : sorts) {
        for (auto array : arrays) {
            for (auto sizes : sizes_list) {
                std::cout << "Processing " << sort.first << " " << array.first << " " << sizes.first << std::endl;

                
            }
        }
    }

    

    return 0;
}