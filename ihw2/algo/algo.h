#include <vector>

std::size_t simple(std::vector<char>& text, std::vector<char>& substr, std::size_t& oper);
std::size_t kmp(std::vector<char>& text, std::vector<char>& substr, std::size_t& oper);
std::size_t cooler_kmp(std::vector<char>& text, std::vector<char>& substr, std::size_t& oper); // уточненные грани