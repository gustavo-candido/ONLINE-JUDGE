#include <stdio.h>

main ()
{
    int N, M, i, A[20000], aux;

    while (scanf("%d %d", &N, &M)!= EOF) {
            if (N==0 && M==0) break;
            else {
                for (i=0; i<=N; i++) A[i]=0;
                for (i=0; i<M; i++) {
                    scanf("%d", &aux);
                    A[aux]++;
                }
                aux=0;
                for (i=0; i<=N; i++) {
                    if (A[i] > 1) {
                        aux++;
                    }
                }
                printf("%d\n", aux);

            }

    }
}