#include <functional>
#include <utility>
#include <vector>

const int retries = 5;
const int textpairs = 50;

std::pair<long long, long long> speedtest(
    std::function<int(std::vector<char>&, std::vector<char>&, std::size_t&)> f,
    std::vector<char>& text, std::vector<char>& substr);