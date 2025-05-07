#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Function to find the number closest to zero
int findClosestToZero(int nums[], int size) {
  if (size == 0) {
    return 0; // Or handle as per requirement if the array is empty
  }

  int closest = nums[0];

  for (int i = 1; i < size; i++) {

    closest = (abs(nums[i]) < abs(closest))                         ? nums[i]
              : (abs(nums[i]) == abs(closest) && nums[i] > closest) ? nums[i]
                                                                    : closest;
  }

  return closest;
}

int greatest(int a, int b, int c) {
  int greatest = (a > b && a > c) ? a : (b > c) ? b : c;
  return greatest;
}

int main() {
  int nums[] = {3, -1, -7, 2, 5, -2};
  int nums1[] = {-4, -2, 1, 4, 8};
  int nums2[] = {2, -1, 1};
  int size = sizeof(nums) / sizeof(nums[0]);
  int size1 = sizeof(nums1) / sizeof(nums1[0]);
  int size2 = sizeof(nums2) / sizeof(nums2[0]);

  int result = findClosestToZero(nums, size);
  int result1 = findClosestToZero(nums1, size1);
  int result2 = findClosestToZero(nums2, size2);
  printf("%d\n", result);
  printf("%d\n", result1);
  printf("%d\n", result2);
  printf("%d", greatest(1, 2, 3));

  return 0;
}
