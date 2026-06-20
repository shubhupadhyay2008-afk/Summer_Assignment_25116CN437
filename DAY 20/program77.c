#include <stdio.h>

int main() {
    int m, n, p, q, i, j, k;
    int A[10][10], B[10][10], C[10][10];

    printf("Enter rows/cols for Matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter rows/cols for Matrix B: ");
    scanf("%d %d", &p, &q);

    if (n != p) {
        printf("Error: Columns of A must equal rows of B.\n");
        return 1;
    }

    printf("Enter Matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++) scanf("%d", &B[i][j]);

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Result:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) printf("%d\t", C[i][j]);
        printf("\n");
    }
    return 0;
}
