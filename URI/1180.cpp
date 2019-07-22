#include <stdio.h>
main ()
{
    int N, menor, posi;
    scanf("%d", &N);
    int X[N], i=0;
    for (i=0; i<N; i++) {
        scanf ("%d", &X[i]);
        if (i==0) {
        menor = X[0];
        posi = i;
        }
        if (menor>X[i]) {
        menor = X[i];
        posi = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posi);
}