#include <stdio.h>
#include <string.h>

main ()
{
    int N, c, tam1, tam2, i, j;
    char A[100], B[100];

    scanf("%d", &N);
    getchar;

    for (c=0; c<N; c++) {
        scanf("%s", A);
        scanf("%s", B);
        tam1 = strlen(A);
        tam2 = strlen(B);
        for (i=tam1-tam2, j=0; j<tam2; i++, j++) {
            if (A[i] != B[j]) {printf("nao encaixa\n"); break;}
            if (j+1 == tam2) printf("encaixa\n");
        }

    }
}