/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
#include <stdlib.h>
int **fourSum(int *nums, int numsSize, int target, int *returnSize,
              int **returnColumnSizes) {
  *returnColumnSizes = malloc(sizeof(int) * (*returnSize));
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 0, -1, 0, -2, 2};
  int numsSize = sizeof(nums) / sizeof(int);
  int target = 0;
  int *returnSize = malloc(sizeof(int));
  int **returnColumnSizes;
  int **result;
  result = fourSum(nums, numsSize, target, returnSize, returnColumnSizes);
  return 0;
}
