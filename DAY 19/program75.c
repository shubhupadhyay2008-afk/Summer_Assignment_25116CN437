#include <stdio.h>

int main() {
    int matrix[10][10], transpose[10][10];
    int rows, cols, i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("Enter element at [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTransposed Matrix:\n");
    for (i = 0; i < cols; ++i) {
        for (j = 0; j < rows; ++j) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
