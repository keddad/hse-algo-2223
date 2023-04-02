#include "gen.h"

#include <cstddef>
#include <cstdlib>
#include <set>

std::pair<std::vector<char>, std::vector<char>> generate_test(
    std::size_t text_size, std::size_t substr_size, std::vector<char> alphabet,
    std::size_t subs) {
  std::vector<char> text(text_size);

  for (std::size_t i = 0; i < text.size(); ++i) {
    text[i] = alphabet[rand() % alphabet.size()];
  }

  std::size_t substr_start = rand() % (text_size - substr_size - 1);

  std::vector<char> substr(text.begin() + substr_start,
                           text.begin() + substr_start + substr_size);

  std::set<size_t> subs_pos;

  for (; subs_pos.size() != subs;) {
    subs_pos.insert(rand() % (substr_size - 1));
  }

  for (size_t pos : subs_pos) {
    substr[pos] = '?';
  }

  return {text, substr};
};