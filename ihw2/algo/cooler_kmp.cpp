#include "algo.h"
#include "util.h"

std::size_t cooler_kmp(std::vector<char>& text, std::vector<char>& substr,
                       std::size_t& oper) {
  std::vector<int64_t> pi = prefix(substr, oper);

  std::vector<int64_t> answ;

  int64_t kol = 0;
  for (std::size_t i = 0; i < text.size(); ++i) {
    while (kol > 0 && substr[kol] != text[i] && substr[kol] != '?') {
      kol = pi[kol - 1];
    }

    if (substr[kol] == text[i] || substr[kol] == '?') {
      ++kol;
    }

    if (kol == static_cast<int64_t>(substr.size())) {
      return i - substr.size();
    }
  }

  return -1;
}