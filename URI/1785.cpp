#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

int min_num (const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int max_num (const void *a, const void *b) {
    return (*(char*)b - *(char*)a);
}

int menor_numero (int x) {
    int menor, tam;
    char A[MAX];
    sprintf(A, "%d", x);
    tam = strlen(A);
    if (tam < 4) {
        for (int i=tam; i<4; i++) {
            A[i] = '0';
        }
    }
    A[4] = '\0';
    qsort(A, strlen(A), sizeof(char), min_num);
    menor = atoi(A);
    return menor;
}

int maior_numero (int x) {
    int maior, tam;
    char A[MAX];
    sprintf(A, "%d", x);
    tam = strlen(A);
    if (tam < 4) {
        for (int i=tam; i<4; i++) {
            A[i] = '0';
        }
    }
    A[4] = '\0';
    qsort(A, strlen(A), sizeof(char), max_num);
    maior = atoi(A);
    return maior;
}

int main ()
{
    int N, X, menor, maior, i;

    scanf("%d", &N);
    for (int c=0; c<N; c++) {
        scanf("%d", &X);
        i=0;
        while(X != 6174) {
           maior = maior_numero(X);
           menor = menor_numero(X);
           X = maior - menor;
           i++;
           if (menor == maior)  break;
        }
        if (X == 6174)printf("Caso #%d: %d\n", c+1, i);
        else printf("Caso #%d: -1\n", c+1);
    }
}
