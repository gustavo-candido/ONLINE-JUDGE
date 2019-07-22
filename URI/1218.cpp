#include <stdio.h>

main ()
{
    int N, X[45], Y[45], i, aux, j=1;
    char A, aux2;
    while (scanf("%d ", &N) != EOF) {
        for (i=20; i<=44; i++) {
            X[i]=0;
            Y[i]=0;
        }
        aux2 = ' ';
        while (aux2 != '\n') {
            scanf("%d %c%c", &aux, &A, &aux2);
            if (A == 'F') X[aux]++;
            else if (A == 'M') Y[aux]++;
        }
        if (j>1) printf("\n");
        printf("Caso %d:\n", j);
        printf("Pares Iguais: %d\n", X[N]+Y[N]);
        printf("F: %d\n", X[N]);
        printf("M: %d\n", Y[N]);
        j++;
    }
}
