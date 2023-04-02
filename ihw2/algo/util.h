#pragma once

#include <cstdint>
#include <vector>

std::vector<int64_t> prefix(std::vector<char>& sub, std::size_t& oper) {
  std::vector<int64_t> tmpbutcheckerisbad(sub.size(), 0);
  std::vector<int64_t> pi(sub.size(), 0);

  for (std::size_t i = 1; i < tmpbutcheckerisbad.size(); ++i) {
    int64_t l = tmpbutcheckerisbad[i - 1];

    oper++;
    while (l > 0 && sub[l] != sub[i] || sub[l] == '?' || sub[i] == '?') {
      l = tmpbutcheckerisbad[l - 1];
    }

    oper++;
    if (sub[l] == sub[i] || sub[l] == '?' || sub[i] == '?') {
      ++l;
    }

    tmpbutcheckerisbad[i] = l;
  }

  for (std::size_t i = 1; i < tmpbutcheckerisbad.size(); ++i) {
    oper++;
    if (sub[tmpbutcheckerisbad[i]] != sub[i + 1] &&
        sub[tmpbutcheckerisbad[i]] != '?' && sub[i + 1] != '?') {
      pi[i] = tmpbutcheckerisbad[i];
    } else {
      pi[i] = pi[tmpbutcheckerisbad[i]];
    }
  }

  return pi;
}