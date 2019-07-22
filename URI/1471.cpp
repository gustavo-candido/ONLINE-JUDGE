#include <stdio.h>

main ()
{
    int A, B, V[10001], i, aux;

    while (scanf("%d %d", &A, &B) != EOF) {
        for (i=0; i<=A; i++) V[i]=0;
        for (i=0; i<B; i++) {
            scanf("%d", &aux);
            V[aux]++;
        }
        aux=0;
        for (i=1; i<=A; i++) {
                if (V[i] == 0) {
                    printf("%d ", i);
                    aux++;
                }
        }
        if (aux==0) printf("*");
        printf("\n");
    }
}
