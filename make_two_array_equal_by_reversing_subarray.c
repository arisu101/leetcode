#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize);
int compare(const void *pa, const void *pb);
int main(int argc, char *argv[]) {

  int ar1[] = {1, 2, 3};
  int ar2[] = {2, 1, 3};
  int *target = ar1;
  int *arr = ar2;
  if (canBeEqual(target, 3, arr, 3))
    printf("equal");
  else
    printf("not equal");
  return 0;
}

int compare(const void *pa, const void *pb) {
  int a = *((int *)pa);
  int b = *((int *)pb);
  return (a > b) - (a < b);
}

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize) {

  qsort(target, targetSize, sizeof(int), compare);
  qsort(arr, targetSize, sizeof(int), compare);
  for (int i = 0; i < targetSize; i++) {
    if (*(target + i) != *(arr + i)) {
      return false;
    }
  }

  return true;
}
