#include <algorithm>
#include <cstdint>
#include <iterator>
#include <vector>

// I was to tired to make it compile properly

inline std::vector<int64_t> prefix(std::vector<char>& sub, std::size_t& oper) {
  std::vector<int64_t> tmpbutcheckerisbad(sub.size(), 0);
  std::vector<int64_t> pi(sub.size(), 0);

  for (std::size_t i = 1; i < tmpbutcheckerisbad.size(); ++i) {
    int64_t l = tmpbutcheckerisbad[i - 1];

    oper++;
    while (l > 0 && sub[l] != sub[i]) {
      l = tmpbutcheckerisbad[l - 1];
    }

    oper++;
    if (sub[l] == sub[i]) {
      ++l;
    }

    tmpbutcheckerisbad[i] = l;
  }

  for (std::size_t i = 1; i < tmpbutcheckerisbad.size(); ++i) {
    oper++;
    if (sub[tmpbutcheckerisbad[i]] != sub[i + 1]) {
      pi[i] = tmpbutcheckerisbad[i];
    } else {
      pi[i] = pi[tmpbutcheckerisbad[i]];
    }
  }

  return pi;
}

inline void rec_parametrizer(std::vector<char>& pattern,
                             const std::vector<char>& alphabet,
                             std::vector<std::vector<char>>& out) {
  auto next_sub = std::find(pattern.begin(), pattern.end(), '?');

  if (next_sub == pattern.end()) {
    out.push_back(pattern);
    return;
  }

  size_t sub_idx = std::distance(pattern.begin(), next_sub);

  for (size_t i = 0; i < alphabet.size(); ++i) {
    pattern[sub_idx] = alphabet[i];
    rec_parametrizer(pattern, alphabet, out);
  }

  pattern[sub_idx] = '?';
}

inline std::vector<std::vector<char>> parametrize(
    std::vector<char>& orig_pattern, const std::vector<char>& alphabet) {
  std::vector<std::vector<char>> out;
  rec_parametrizer(orig_pattern, alphabet, out);
  return out;
}