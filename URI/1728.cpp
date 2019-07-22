#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inverte (char A[], int tam){ /*Recebe um vetor char inverte e o transforma em inteiro*/
    char B[100];
    int j, i, Y;
    for (i=0, j=tam-1; i<tam; i++, j--) {
        B[i] = A[j];
    }
    B[i]='\0';
    Y = atoi(B);
    return Y;
}
main ()
{
    int a, b, c, d, k, l;
    char x[100], A[100], B[100], C[100];
    /*
    a = primeiro numero da entrada
    b = segundo numero da entrada
    c = resultado da entrada
    d = soma de a com b
    x = vetor pra ler a expressao inteira
    p = ponteiro para strtok
    */
    while (scanf("%s", x) != EOF) {
        getchar();
        for(k=0; k<100; k++) {
            A[k]=0;
            B[k]=0;
            C[k]=0;
        }
        strcpy(A, strtok (x, "+"));

        l = strlen(A);

        a = inverte(A, l);

        strcpy(B, strtok(NULL, "="));

        l = strlen(B);

        b = inverte(B, l);

        strcpy(C, strtok(NULL, "\n"));

        l = strlen(C);

        c = inverte(C, l);

        d = a+b;

        if (d == c) printf("True\n");
        else printf("False\n");
        if (a==0 && b==0 && c==0) break;
        for(k=0; k<100; k++) {
            A[k]=0;
            B[k]=0;
            C[k]=0;
        }
  }
}
