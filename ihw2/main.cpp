#include <cstddef>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

#include "algo/algo.h"
#include "perf/gen.h"
#include "perf/perf.h"

std::map<std::string,
         std::function<std::size_t(std::vector<char> &, std::vector<char> &,
                                   std::vector<char> &, std::size_t &)>>
    algos{
        {"kmp", kmp},
        {"simple", simple},
        {"cooler_kmp", cooler_kmp},
    };

std::map<std::string, std::vector<char>> alphabets{
    {"binary", BINARY_ALPHABET}, {"nonbinary", NONBINARY_ALPHABET}};

int main() {
  size_t random_seed = time(nullptr);
  std::string data_path = "data.csv";

  std::ofstream out(data_path);

  if (!out) {
    return 1;
  }

  out << "algo,alphabet,text_size,pattern_size,sub_cnt,avg_time,avg_oper\n";

  for (auto algo : algos) {
    srand(random_seed);

    for (auto alphabet : alphabets) {
      std::cout << "Processing " << algo.first << " " << alphabet.first
                << std::endl;

      for (size_t sub_cnt = 0; sub_cnt < 5; ++sub_cnt) {
        for (size_t text_size = 10000; text_size <= 100000; text_size *= 10) {
          for (size_t pattern_size = 100; pattern_size <= 3000;
               pattern_size += 100) {
            std::cout << algo.first << ' ' << alphabet.first << ' ' << sub_cnt << ' ' << text_size << '\n';
            
            long long avg_time = 0, avg_oper = 0;

            for (size_t text_i = 0; text_i < textpairs; ++text_i) {
              auto data = generate_test(text_size, pattern_size,
                                        alphabet.second, sub_cnt);
              auto res = speedtest(algo.second, data.first, data.second,
                                   alphabet.second);

              avg_time += res.first;
              avg_oper += res.second;
            }

            avg_time /= textpairs;
            avg_oper /= textpairs;

            out << algo.first << ',' << alphabet.first << ',' << text_size
                << ',' << pattern_size << ',' << sub_cnt << ',' << avg_time
                << ',' << avg_oper << '\n';
          }
        }
      }
    }
  }

  return 0;
}