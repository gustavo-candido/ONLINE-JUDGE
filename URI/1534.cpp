#include <stdio.h>

main ()
{
    int N;
    while (scanf("%d", &N) != EOF) {
        int matriz[N][N], um=0, dois=N-1, x, y;

        for (x=0; x<N; x++) {
            for (y=0; y<N; y++) {
                if (y==dois) {
                    matriz[x][y] = 2;
                }
                else if (y==um) {
                    matriz[x][y] = 1;
                }
                else {
                    matriz[x][y] = 3;
                }
            }
            um++;
            dois--;
        }

         for (x=0; x<N; x++) {
            for (y=0; y<N; y++) {
                    printf("%d", matriz[x][y]);
            }
            printf("\n");
         }
    }
}