#include <stdio.h>
#include <math.h>
#define n 5

void bul(int A[n][n]);
void sa(int A[n][n]);
void main(void){
    int i, j, k;
    int A[n][n];
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("a[%d][%d]=", i + 1, j + 1);
            scanf_s("%d", &A[i][j]);
        }
    }
    printf("Old matrix \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++)
            printf("%5d", A[i][j]);
        printf("\n");
    }
    bul(A);
    printf("\n New matrix \n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
    sa(A);
}

void bul(int A[][n]){
    int i, k, j, c;
    for (j = 0; j < n; j++){
        for (k = n - 1; k >= 0; k--){
            for (i = 0; i < k; i++){
                if (A[i][j] > A[i + 1][j]){
                    c = A[i][j];
                    A[i][j] = A[i + 1][j];
                    A[i + 1][j] = c;
                }
            }
        }
    }
}

void sa(int A[][n]){
    int i, j;
    double f, F;
    F = 0;
    for (i = 0; i < n; i++){
        f = 1;
        for (j = 0; j < n; j++){
            f = f * A[i][j];


        }
        f = (f < 0 ? -pow(-f, 0.2) : pow(f, 0.2));
        F += f ;
        printf("\n f[%d]=%lf", i + 1, f);
    }
    printf("\n F=%lf", F/5);
}