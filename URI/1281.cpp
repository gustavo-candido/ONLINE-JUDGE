#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main ()
{
    int N, c, M, i, P, j, aux2;
    float *X, T;
    char aux[60];

    scanf("%d", &N);

    for (c=0; c<N; c++) {
        scanf("%d ", &M);
        char A[M][50];
        T=0;
        X = (float*)malloc(M*sizeof(float));
        for (i=0; i<M; i++) {
            scanf("%s %f", &A[i], &X[i]);
        }
        scanf("%d", &P);
        for (i=0; i<P; i++) {
            scanf(" %s %d ", &aux, &aux2);
            for (j=0; j<M; j++) {
                if (strcmp(aux, A[j]) == 0) {
                    T+=(aux2 * X[j]);
                }
            }
        }
        printf("R$ %.2f\n", T);
    }
}
