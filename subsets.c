/**
 * return an array of arrays of size *returnsize.
 * the sizes of the arrays are returned as *returncolumnsizes array.
 * note: both returned array and *columnsizes array must be malloced, assume
 * caller calls free().
 */
// return columnsizes returns the actual subsets
// returnsize returns the no of subsetes
#include <stdio.h>
#include <stdlib.h>

int **subsets(int *nums, int numsSize, int *returnSize,
              int **returnColumnSizes) {
  *returnSize = 1 << numsSize;
  int **result = (int **)malloc(*returnSize * sizeof(int **));
  *returnColumnSizes = malloc(*returnSize * sizeof(int **));
  for (int i = 0; i < *returnSize; i++) {
    int *current_subset = malloc(sizeof(int) * numsSize);
    int current_size = 0;
    for (int j = 0; j < numsSize; j++) {
      if (i & (1 << j)) {
        current_subset[current_size++] = nums[j];
      }
    }
    result[i] = current_subset;
    (*returnColumnSizes)[i] = current_size;
  }
  return result;
}

int main(int argc, char *argv[]) {
  int nums[] = {5, 2, 1};
  int numsSize = sizeof(nums) / sizeof(int);
  int *returnsize = malloc(sizeof(int));
  *returnsize = 1 << numsSize;
  int *returncolumnsizes = malloc(*returnsize * sizeof(int));
  int **result = subsets(nums, numsSize, returnsize, &returncolumnsizes);
  for (int i = 0; i < *returnsize; i++) {
    for (int j = 0; j < returncolumnsizes[i]; j++) {
      printf("%d", result[i][j]);
      if (j < returncolumnsizes[i] - 1) {
        printf(", ");
      }
    }
    printf("\n");
  }
  free(returnsize);
  free(returncolumnsizes);
  for (int i = 0; i < *returnsize; i++) {
    free(result[i]);
  }
  free(result);
  return 0;
}
