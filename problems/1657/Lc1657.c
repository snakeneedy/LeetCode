#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int desc(const void* larg, const void* rarg) {
  int lval = *(const int*)larg, rval = *(const int*)rarg;
  return (lval < rval) - (lval > rval);
}

bool closeStrings(char* word1, char* word2) {
  size_t word1size = strlen(word1), word2size = strlen(word2);
  if (word1size != word2size)
    return false;

  int freq1[26] = {0}, freq2[26] = {0};
  for (size_t pos = 0; pos < word1size; ++pos)
    ++freq1[word1[pos] - 'a'];
  for (size_t pos = 0; pos < word2size; ++pos)
    ++freq2[word2[pos] - 'a'];
  for (size_t pos = 0; pos < 26; ++pos) {
    if ((freq1[pos] == 0) != (freq2[pos] == 0))
      return false;
  }
  qsort(freq1, 26, sizeof(int), desc);
  qsort(freq2, 26, sizeof(int), desc);
  for (size_t pos = 0; pos < 26; ++pos) {
    if (freq1[pos] != freq2[pos])
      return false;
    if (freq1[pos] == 0 && freq2[pos] == 0)
      break;
  }
  return true;
}

void testcase01() {
  char* word1 = "abc";
  char* word2 = "bca";
  bool result = closeStrings(word1, word2);
  bool expected = true;
  assert(expected == result);
}

void testcase02() {
  char* word1 = "a";
  char* word2 = "aa";
  bool result = closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

void testcase03() {
  char* word1 = "cabbba";
  char* word2 = "abbccc";
  bool result = closeStrings(word1, word2);
  bool expected = true;
  assert(expected == result);
}

void testcase04() {
  char* word1 = "abbzccca";
  char* word2 = "babzzczc";
  bool result = closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

void testcase05() {
  char* word1 = "aaabbbbccddeeeeefffff";
  char* word2 = "aaaaabbcccdddeeeeffff";
  bool result = closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

void testcase06() {
  char* word1 = "uau";
  char* word2 = "ssx";
  bool result = closeStrings(word1, word2);
  bool expected = false;
  assert(expected == result);
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  testcase04();
  testcase05();
  testcase06();
  return 0;
}
