#include <stdio.h>
 
main ()
{
    int N, de, ate, i, aux;
 
    while (scanf("%d", &N) != EOF) {
        if (N % 2 == 0) N/=2;
        else N = N/2+1;
        de = N;
        aux = N;
        ate = N;
        i=0;
 
        while (de!=0) {
            while (1) {
            if (i >= de && i <= ate) printf("*");
            else if (i<de-1) printf(" ");
            if (i==ate) {
                printf("\n");
                i=0;
                break;
            }
        i++;}
        de--;
        ate++;
        }
        for (i=0; i<aux-1; i++) printf(" ");
        printf("*\n");
        for (i=0; i<aux-2; i++) printf(" ");
        printf("***\n\n");
    }
}