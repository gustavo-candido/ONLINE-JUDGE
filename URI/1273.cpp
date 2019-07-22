#include <stdio.h>
#include <string.h>
 
main ()
 
{
    int i=0, j=0, z, maior=0, tam, c=0, x=0;
    char A[100][100];
    while (scanf(" %d", &z) != EOF) {
        if (x != 0 && z != 0) {
            printf("\n");
        }
        if (z==0) {
            break;
        }
        else {
            maior = 0;
            for (i=0; i<z; i++) {
                scanf(" %[^\n]", &A[i]);
                tam = strlen(A[i]);
 
                if (tam>maior) {
                    maior = tam;
                }
            }
 
            for (i=0; i<z; i++) {
                j=0;
                tam = strlen(A[i]);
                       for (c=0; c<maior-tam; c++) {
                        printf(" ");
                    }
                while (A[i][j] != '\0') {
                    printf("%c", A[i][j]);
                    j++;
                }
                printf("\n");
            }
            x=1;
        }
    }
}