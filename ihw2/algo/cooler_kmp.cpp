#include "algo.h"
#include "util.h"

std::size_t cooler_kmp_internal(std::vector<char>& text,
                                std::vector<char>& substr, std::size_t& oper) {
  std::vector<int64_t> pi = prefix(substr, oper);

  std::vector<int64_t> answ;

  int64_t kol = 0;
  for (std::size_t i = 0; i < text.size(); ++i) {
    while (kol > 0 && substr[kol] != text[i]) {
      kol = pi[kol - 1];
    }

    if (substr[kol] == text[i]) {
      ++kol;
    }

    if (kol == static_cast<int64_t>(substr.size())) {
      return (i + 1) - substr.size();
    }
  }

  return -1;
}

std::size_t cooler_kmp(std::vector<char>& text, std::vector<char>& substr,
                       const std::vector<char>& alphabet, std::size_t& oper) {
  for (auto pattern : parametrize(substr, alphabet)) {
    std::size_t answ = cooler_kmp_internal(text, pattern, oper);

    if (answ != -1) {
      return answ;
    }
  }

  return -1;
}