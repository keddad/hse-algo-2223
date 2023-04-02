#include <cstddef>

#include "algo.h"

std::size_t simple(std::vector<char>& text, std::vector<char>& substr,
                   std::size_t& oper) {

  for (std::size_t start_point = 0; start_point < text.size() - substr.size(); ++start_point) {
    std::size_t offset = 0;
    for (; offset < substr.size(); ++offset) {
      oper++;
      if (text[start_point + offset] == substr[offset] || substr[offset] == '?') {
        continue;
      }

      break;
    }

    if (offset == substr.size()) {
      return start_point;
    }
  }

  return -1; // overflow goes brrrr
}