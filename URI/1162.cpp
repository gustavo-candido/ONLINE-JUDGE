#include <stdio.h>

main ()
{
    int NC, N, i, j, aux, A[100], x;

    scanf("%d", &NC);

    for (NC=NC; NC>0; NC--) {
        scanf("%d", &N);
        for (i=0; i<N; i++) {
            scanf("%d", &A[i]);
        }
        x=0;
        for (i=0; i<N; i++) {
            for (j=0; j<N-1; j++) {
                if (A[j]>A[j+1]) {
                    aux = A[j];
                    A[j] = A[j+1];
                    A[j+1]=aux;
                    x++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", x);
    }
}