#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

char* removeStars(char* s) {
  size_t size = strlen(s), lpos = 0;
  char* buf = (char*)malloc((size + 1) * sizeof(char));
  for (size_t rpos = 0; rpos < size; ++rpos) {
    if (s[rpos] == '*') {
      if (lpos > 0)
        --lpos;
    } else {
      buf[lpos++] = s[rpos];
    }
  }
  buf[lpos] = '\0';
  return buf;
}

void testcase01() {
  char* s = "leet**cod*e";
  char* result = removeStars(s);
  char* expected = "lecoe";
  assert(strcmp(expected, result) == 0);
}

void testcase02() {
  char* s = "erase*****";
  char* result = removeStars(s);
  char* expected = "";
  assert(strcmp(expected, result) == 0);
}

void testcase03() {
  char* s = "erase";
  char* result = removeStars(s);
  char* expected = "erase";
  assert(strcmp(expected, result) == 0);
}

int main() {
  testcase01();
  testcase02();
  testcase03();
  return 0;
}
