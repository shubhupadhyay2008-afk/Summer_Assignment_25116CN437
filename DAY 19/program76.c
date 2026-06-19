#include <stdio.h>

int main() {
    int n, i, j;
    int main_diagonal_sum = 0;
    int opposite_diagonal_sum = 0;

    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        main_diagonal_sum += matrix[i][i];
        opposite_diagonal_sum += matrix[i][n - i - 1];
    }

    printf("\nThe given matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSum of Main Diagonal elements: %d\n", main_diagonal_sum);
    printf("Sum of Opposite Diagonal elements: %d\n", opposite_diagonal_sum);

    return 0;
}
