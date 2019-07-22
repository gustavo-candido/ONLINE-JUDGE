#include <stdio.h>
main ()
{
    int N, i=0, j=0;
    while (scanf("%d", &N) != EOF) {
        if (N==0) {
            break;
        }
        else {
            int matrix[N][N], num;

            for (i=0; i<N; i++) {
                    num = i+1;
                for (j=0; j<N; j++) {

                    if (i != j && j<i) {
                        matrix[i][j] = num;
                        num--;
                    }
                    if (i == j || i != j && j>i) {
                        matrix[i][j] = num;
                        num++;
                    }
                }
            }

            for (i=0; i<N; i++) {
                for (j=0; j<N; j++) {
                    if (j == N-1) {
                        printf("%3d", matrix[i][j]);
                        printf("\n");
                    }
                    else {
                        printf ("%3d ", matrix[i][j]);
                    }
                }
            }
        }
        printf ("\n");
    }
}
