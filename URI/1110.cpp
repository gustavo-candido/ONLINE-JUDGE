#include <stdio.h>
#include <stdlib.h>

main()
{
    int N, *p, tam, i, aux;

    while (scanf("%d", &N) != EOF) {
        if (N==0) break;
        tam = N;
        p = (int*)malloc(N*sizeof(int));
        for (i=0; i<tam; i++) {
            p[i] = N-i;
        }
        printf("Discarded cards:");
        while (tam>1) {
                if (tam==N) printf(" %d", p[tam-1]);
                else printf(", %d", p[tam-1]);
            tam--;
            aux= p[tam-1];
            for (i=tam-2; i>=0; i--) {
                p[i+1] = p[i];
            }
            p[0]=aux;
        }
        printf("\nRemaining card: %d\n", p[0]);
    }
}