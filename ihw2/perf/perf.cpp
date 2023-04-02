#include "perf.h"

#include <chrono>
#include <cstddef>
#include <iostream>

std::pair<long long, long long> speedtest(
    std::function<int(std::vector<char>&, std::vector<char>&, std::size_t&)> f,
    std::vector<char>& text, std::vector<char>& substr) {
  long long time = 0;
  std::size_t op_count = 0;

  for (int i = 0; i < retries; i++) {
    auto t1 = std::chrono::high_resolution_clock::now();
    f(text, substr, op_count);
    auto t2 = std::chrono::high_resolution_clock::now();

    time +=
        std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
  }

  return std::make_pair(time / retries, op_count);
}
