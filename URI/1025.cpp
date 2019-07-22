#include <stdio.h>
#include <stdlib.h>

int compara (const void *a, const void *b) {
    return *(const int*) a - *(const int*) b;
}

int busca (int A[], int B, int N) {
    int de=0, ate=N-1, x=-1, meio, i;
    while (de<=ate && x==-1) {
        meio = de + ((ate-de)/2);
        if (A[meio]<B) {
            de = meio+1;
        }
        else if (A[meio]>B) {
            ate = meio-1;
        }
        else x=meio;
    }
     for (i=x; i>=0; i--) {
        if (A[x]==A[i]) {
            x=i;
        }
        else break;
     }
     return x;
}
main ()
{
    int N, Q, c, *A, B, x, j=1;

    while (scanf("%d %d", &N, &Q) != EOF) {
        if (N==0 && Q==0) break;
        A = (int*)malloc(N*sizeof(int));
        for (c=0; c<N; c++) {
            scanf("%d", &A[c]);
        }
        qsort(A, N, sizeof(int), compara);
        printf("CASE# %d:\n", j);
        for (c=0; c<Q; c++) {
            scanf("%d", &B);
            x = busca(A, B, N);
            if (x==-1) printf("%d not found\n", B);
            else printf("%d found at %d\n", B, x+1);
        }
        j++;
        free(A);
    }
}
