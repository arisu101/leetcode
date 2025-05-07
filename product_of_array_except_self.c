/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *result = (int *)malloc(numsSize * sizeof(int));
  int left = 1, right = 1;
  for (int i = 0; i < numsSize; i++) {
    result[i] = left;
    left *= nums[i];
  }
  for (int j = numsSize - 1; j >= 0; j--) {
    result[j] *= right;
    right *= nums[j];
  }
  return result;
}

int main(int argc, char *argv[]) {
  int num[] = {-1, 1, 0, -3, 3};
  int returnSize = 0;
  int *result = productExceptSelf(num, sizeof(num) / sizeof(int), &returnSize);
  for (int i = 0; i < sizeof(num) / sizeof(int); i++) {
    printf("%d\n", result[i]);
  }
  free(result);
  return 0;
}

/*
 * QUESTION: [1,2,3,4]
 * PREFIX:   [1,2,6,24]
 * SUFFIX:   [24,24,12,4]
 * ANSWER:   [24,12,8,6]
 * */
