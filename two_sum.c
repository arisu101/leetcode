#include <stdio.h>
#include <stdlib.h>

/**
 *
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main(int argc, char *argv[]) {

  int a1[5] = {1, 2, 3, 4, 6};

  int a2[] = {0};
  int *returnSize = a2;
  int *nums = a1;

  int target = 10;
  /* printf("%d", twoSum(nums, 3, target, returnSize)); */
  int *returna = twoSum(nums, 5, target, returnSize);
  for (int i = 0; i < 2; i++) {
    printf("%d,", *(returna + i));
  }
  free(returna);

  return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (*(nums + i) + *(nums + j) == target) {
        int *result = (int *)malloc(2 * sizeof(int));
        *(result) = i;
        *(result + 1) = j;
        *returnSize = 2;
        return result;
      }
    }
  }
  return NULL;
}
