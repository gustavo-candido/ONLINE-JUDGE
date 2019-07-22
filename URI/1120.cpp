#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void revisao (char A[], char B[]) {
    char aux[100000];
    int i, j, tam, ah=0;
    unsigned long long int x;
    tam = strlen(B);

    for (i=0, j=0; i<tam; i++) {
        if (B[i] != A[0]) {
            aux[j] = B[i];
            j++;
            if (aux[i] != aux[i-1]) {
                ah++;
            }
        }
    }
        i = 0;
        while (aux[i] == '0') {
         i++;
        }
        x = atoi(aux);
        if (x != 0 && ah != 0) {
        while  (i<j) {
            printf("%c", aux[i]);
            i++;
        }
        printf("\n");
        }
        else printf("0\n");
}
main ()
{
    char A[10], B[100000];
    unsigned long long int a, b;
    while (1) {
            scanf("%d", &a);
            sprintf(A, "%d", a);
            getchar();
            gets(B);
            b = atoi(B);

            if (a == 0 && b == 0) {
                break;
            }
            else {
                revisao (A, B);
            }

    }
}
