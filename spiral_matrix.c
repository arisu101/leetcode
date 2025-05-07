#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *spiralOrder(int **matrix, int matrixSize, int *matrixColSize,
                 int *returnSize) {}

int main() {
  int matrixSize = 3;              // Number of rows
  int matrixColSize[] = {3, 3, 3}; // Number of columns for each row (in this
                                   // case all rows have 3 columns)

  // Dynamically allocate memory for the matrix (3 rows)
  int **matrix = (int **)malloc(matrixSize * sizeof(int *));

  // Dynamically allocate memory for each row (each row has 3 columns)
  for (int i = 0; i < matrixSize; i++) {
    matrix[i] = (int *)malloc(matrixColSize[i] * sizeof(int));
  }

  // Initialize matrix with some values (example)
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;

  // Now you can call your spiralOrder function here
  // int *result = spiralOrder(matrix, matrixSize, matrixColSize, &returnSize);

  // Clean up allocated memory
  for (int i = 0; i < matrixSize; i++) {
    free(matrix[i]); // Free each row
  }
  free(matrix); // Free the matrix itself

  return 0;
}
