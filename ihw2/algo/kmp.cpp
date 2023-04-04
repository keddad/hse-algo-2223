#include "algo.h"
#include "util.h"

std::size_t kmp(std::vector<char>& text, std::vector<char>& substr,
                const std::vector<char>& alphabet, std::size_t& oper) {
  std::vector<int64_t> next(substr.size() + 1, 0);

  for (std::size_t i = 1; i < substr.size(); i++) {
    int64_t j = next[i + 1];

    while (j > 0 && substr[j] != substr[i] && substr[i] != '?' &&
           substr[j] != '?') {
      oper++;
      j = next[j];
    }

    oper++;
    if (j > 0 || substr[j] == substr[i] || substr[i] == '?' ||
        substr[j] == '?') {
      next[i + 1] = j + 1;
    }
  }

  for (std::size_t i = 0, j = 0; i < text.size(); i++) {
    oper++;
    if (text[i] == substr[j] || substr[j] == '?') {
      if (++j == substr.size()) {
        return i - j + 1;
      }
    } else if (j > 0) {
      j = next[j];
      i--;
    }
  }

  return -1;
}