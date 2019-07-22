#include <stdio.h>
#include <string.h>

main ()
{
    int N;

    while (scanf("%d", &N) != EOF) {
        int matriz[N][N], h, i, j, tam, num=1, max;
        char TAM [10000], HAV [10000];
        if (N == 0) {
            break;
        }
        else {

            for (i=0; i<N; i++) {
                for (j=0; j<N; j++) {
                    matriz[i][j] = num;
                    num = num * 2;
                }
                num = matriz[i][1];
            }

            sprintf (TAM, "%d", matriz[N-1][N-1]);
            max = strlen (TAM);

            for (i=0; i<N; i++) {
                for (j=0; j<N; j++) {
                        sprintf(HAV, "%d", matriz[i][j]);
                        tam = strlen (HAV);
                        for (h=0; h<max - tam; h++) {
                            printf(" ");
                        }
                        if (j==N-1) {
                        printf("%d", matriz[i][j]);
                        }
                        else {
                            printf("%d ", matriz[i][j]);
                        }
                }
                printf("\n");
            }
        }
        printf ("\n");
    }
}