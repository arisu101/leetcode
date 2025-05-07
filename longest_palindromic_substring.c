#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _MAX(a, b) ((a) > (b) ? a : b)

char *longestPalindrome(char *s) {
  int n = strlen(s);
  
  // Handle edge cases
  if (n == 0) return NULL;
  if (n == 1) return s;

  // Create the transformed string
  char *t = (char *)malloc(2 * n + 3);
  t[0] = '$';
  t[1] = '#';

  for (int i = 0; i < n; i++) {
    t[2 * i + 2] = s[i];
    t[2 * i + 3] = '#';
  }
  t[2 * n + 2] = '\0';

  // Manacher's algorithm to find the longest palindrome
  int m = 2 * n + 1;
  int *p = (int *)calloc(m, sizeof(int)); // p[i] will hold the radius of palindrome centered at i
  int C = 0, R = 0;
  for (int i = 1; i < m - 1; i++) {
    int mirror = 2 * C - i;
    if (i < R) {
      p[i] = _MAX(p[mirror], R - i);
    }
    while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
      p[i]++;
    }
    if (i + p[i] > R) {
      C = i;
      R = i + p[i];
    }
  }

  // Find the maximum palindrome length and its center index
  int max_len = 0, center_index = 0;
  for (int i = 1; i < m - 1; i++) {
    if (p[i] > max_len) {
      max_len = p[i];
      center_index = i;
    }
  }

  // Calculate the starting index of the palindrome in the original string
  int start = (center_index - max_len) / 2;

  // Allocate memory for the result and copy the substring
  char *result = (char *)malloc(max_len + 1);
  strncpy(result, s + start, max_len);
  result[max_len] = '\0';

  // Free allocated memory
  free(t);
  free(p);
  
  return result;
}

int main(int argc, char *argv[]) {
  char str[] = "aacabdkacaa";
  char *result = longestPalindrome(str);
  
  if (result != NULL) {
    printf("%s\n", result);
    free(result);
  } else {
    printf("No palindrome found.\n");
  }
  
  return EXIT_SUCCESS;
}
