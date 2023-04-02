#include <array>
#include <utility>
#include <vector>

const std::vector<char> BINARY_ALPHABET = {'0', '1'};
const std::vector<char> NONBINARY_ALPHABET = {'C', 'A', 'T', 'S'};

std::pair<std::vector<char>, std::vector<char>> generate_test(
    std::size_t text_size, std::size_t substr_size, std::vector<char> ahlpabet,
    std::size_t subs = 0);