#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool repeatedSubstringPattern(const char *s) {
  const int len = strlen(s);

  for (int i = len / 2; i > 0; --i) {
    if (len % i == 0) {
      int j;
      for (j = i; j < len; ++j) {
        if (s[j] != s[j % i])
          break;
      }
      if (j == len)
        return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  const char s[] = "acac";
  printf("%b", repeatedSubstringPattern(s));
  return 0;
}
