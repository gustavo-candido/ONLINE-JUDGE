#include <stdio.h>

main ()
{
    int N, uh, wo;

    while (scanf("%d", &N) != EOF) {

        int matrix [N][N], i, j, k;

        if (N==0) {
            break;
        }
        else {
            for (i = 0; i < N; i++) {
                uh = 0;
                for (j = i, k = 0; j >= 0; j--, k++) {
                    if (i % 2 == 0) {
                        if (j >= (i/2)) {
                            uh++;
                        }
                        else {
                            uh--;
                        }
                        }
                        else {
                            if (j > k) {
                                uh++;
                            }
                            if (k > j+1) {
                                uh--;
                            }
                        }
                matrix[j][k] = uh;
                }
            }
            for (i = N-1; i > 0; i--) {
                    uh = 0;
                    for (j = N-1, k = i; k < N; j--, k++) {
                            if (j >= k) {
                                uh++;
                            }
                            if (k > j+1) {
                                uh--;
                            }
                            matrix[j][k] = uh;
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
