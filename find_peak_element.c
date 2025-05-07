#include <stdio.h>

int findPeakElement(int *nums, int numsSize) {

  int left = 0;
  int right = numsSize - 1;
  int mid = 0;

  if (numsSize == 1) {
    return 0;
  }

  while (left <= right) {
    mid = left + ((right - left) / 2);
    if (mid > 0 && nums[mid] < nums[mid - 1]) {
      right = mid - 1;
    }

    else if (mid < numsSize - 1 && nums[mid] < nums[mid + 1]) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return mid;
}

int main(int argc, char *argv[]) {
  int nums[] = {1, 2, 3, 4, 5};
  int numsSize = sizeof(nums) / sizeof(int);
  printf("%d", findPeakElement(nums, numsSize));
  return 0;
}
