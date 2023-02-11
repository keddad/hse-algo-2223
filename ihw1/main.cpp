#include <map>
#include <string>
#include <functional>
#include <iostream>
#include <vector>
#include <fstream>

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
        {"random0-5", getRandom(4101, 0, 5)},
        {"random0-4000", getRandom(4101, 0, 4000)},
        {"almost0-4000", getAlmosrtSorted(4101, 0, 4000)},
        {"reverse4100-1", getReverseSorted(4101, 1, 4100)},
    };

    std::string data_path = argv[1];
    std::cout << data_path << std::endl;

    for(auto sort : sorts) {
        for (auto array : arrays) {
            for (auto sizes : sizes_list) {
                std::cout << "Processing " << sort.first << " " << array.first << " " << sizes.first << std::endl;

                std::ofstream out(data_path + "/" + sort.first + "_" + array.first + "_" + sizes.first + ".csv");
                
                if (!out) {
                    std::cerr << "Can't create file!\n";
                    std::cerr << data_path + "/" + sort.first + "_" + array.first + "_" + sizes.first + ".csv" << std::endl;
                    return 1;
                }

                out << "size,time_ns,operations\n";

                for (auto size : sizes.second) {
                    std::vector<int> to_sort(array.second.begin(), array.second.begin() + size + 1);

                    auto res = speedtest(sort.second, to_sort);

                    out << size << "," << res.first << "," << res.second << "\n";
                }

                out.close();
            }
        }
    }

    

    return 0;
}