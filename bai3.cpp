#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int test = 1; test <= t; test++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int A[n][m], AT[m][n], C[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
                AT[j][i] = A[i][j];
            }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                C[i][j] = 0;
                for (int k = 0; k < m; k++)
                    C[i][j] += A[i][k] * AT[k][j];
            }

        printf("Test %d:\n", test);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%d ", C[i][j]);
            printf("\n");
        }
    }
    return 0;
}

