#include <stdio.h>

main ()
{
    int N, C, n, c, i, j, aux;
    scanf("%d", &N);

    for (C=0; C<N; C++) {
        scanf("%d", &n);
        int A[n], B[n], x=0;

        for (c=0; c<n; c++) {
            scanf("%d", &A[c]);
            B[c] = A[c];
        }

        for (i=0; i<n; i++) {
            for (j=0; j<n-1; j++) {
                if (A[j] < A[j+1]) {
                    aux = A[j];
                    A[j] = A[j+1];
                    A[j+1] = aux;
                }
            }
        }

        for (i=0; i<n; i++) {
            if (B[i] == A[i]) x++;
        }

        printf("%d\n", x);
    }
}