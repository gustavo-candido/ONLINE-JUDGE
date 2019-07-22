#include <stdio.h>
#include <string.h>
main ()
{
    int i, j, c, x;
    char aux, A[60][30], aux2;

    while (1) {
        x=0;
        i=0;
        j=0;
        scanf("%c", &aux);
            if (aux == '*') break;
        while (1) {
            if (x==0 && aux != ' ') {
                    x=1;
                    aux2 = aux;
            }
            if (aux == ' ') {
                A[i][j] = '\0';
                i++;
                j=0;
            }
            else if (aux=='\n')break;
            else {
                A[i][j] = aux;
                j++;
            }
            scanf("%c", &aux);
        }
        c = i;
        for (i=0; i<=c; i++) {
            if (A[i][0]>=65 && A[i][0]<=90 && A[i][0] != aux2) {
                A[i][0]+=32;
                if (A[i][0] != aux2) {
                    printf("N\n");
                    break;
                }
            }
            else if (A[i][0]>=97 && A[i][0]<=122 && A[i][0] != aux2) {
                A[i][0]-=32;
                if (A[i][0] != aux2) {
                    printf("N\n");
                    break;
                }
            }
            if (i==c) printf("Y\n");
        }
    }
}
