#include <stdio.h>
#include <string.h>
main ()
{
    char A[50], aux[50];
    int cent, i, tam;

    while (scanf("%s %d", A, &cent) != EOF) {
            printf("$");
            tam = strlen(A);
        for (i=0; i<strlen(A); i++) {
            if  (i!=0 && tam%3==0) {
                printf(",");
            }
            printf("%c", A[i]);
            tam--;
        }
        printf(".");
        if (cent<10) {
            printf("0");
        }
        printf("%d\n", cent);
    }
}