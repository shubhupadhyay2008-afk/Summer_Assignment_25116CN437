#include <stdio.h>

int main() {
    int rows, cols, i, j;
    int matrix[10][10]; 
    
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe Matrix is:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Column-wise Sum ---\n");
    for (j = 0; j < cols; j++) {
        int colSum = 0; 
        for (i = 0; i < rows; i++) {
            colSum += matrix[i][j]; 
        }
        printf("Sum of Column %d = %d\n", j + 1, colSum);
    }

    return 0;
}
