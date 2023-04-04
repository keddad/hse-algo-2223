#include <functional>
#include <utility>
#include <vector>

const int retries = 10;
const int textpairs = 100;

std::pair<long long, long long> speedtest(
    std::function<int(std::vector<char>&, std::vector<char>&, std::vector<char>&, std::size_t&)> f,
    std::vector<char>& text, std::vector<char>& substr, std::vector<char>& alphabet);