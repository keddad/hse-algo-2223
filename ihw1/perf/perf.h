#include <vector>
#include <utility>
#include <functional>

const int retries = 16;

std::pair<long long, long long> speedtest(std::function<int(std::vector<int> &)> f, std::vector<int> &v);

std::vector<int> smallSizes();
std::vector<int> bigSizes();