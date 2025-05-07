#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX(a, b) ((a) > (b) ? (a) : (b))

int _check(char *s, int left, int right);
char *longestPalindrome(char *s) {
  int start = 0, end = 0;
  int i = 0;
  for (int i = 0; i < strlen(s); i++) {
    int len2 = _check(s, i, i + 1);
    int len1 = _check(s, i, i);
    int len = _MAX(len1, len2);
    if (len > end - start) {
      start = i - ((len - 1) / 2);
      end = i + (len / 2);
    }
  }
  char *result = (char *)malloc(((end - start) + 2) * sizeof(char));
  if (result == NULL) {
    return NULL;
  }
  strncpy(result, s + start, end - start + 1);
  result[end - start + 1] = '\0';
  return result;
}

int _check(char *s, int left, int right) {
  if (s == NULL || left == right) {
    return 0;
  }
  while (left >= 0 && right != '\0' && *(s + left) == *(s + right)) {
    left--;
    right++;
  }
  return right - left - 1;
}

int main(int argc, char *argv[]) {
  char s[] = "babad";
  printf("%s", longestPalindrome(s));
  return EXIT_SUCCESS;
}
