#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main ()
{
    char A[1000];
    int x=0;
    while (gets(A) != NULL) {
        int i, j, aux, V[256] = {0}, Val[10000], aux2;
        for (i=0; i<strlen(A); i++){
            aux = A[i];
            V[aux]++;
            Val[aux] = aux;
        }
        for (i=0; i<256; i++) {
            for (j=0; j<255; j++) {
                if (V[j]>V[j+1]) {
                    aux = V[j];
                    V[j] = V[j+1];
                    V[j+1] = aux;
                    aux2 = Val[j];
                    Val[j] = Val[j+1];
                    Val[j+1] = aux2;
                }
                else if (V[j] == V[j+1]) {
                    if (Val[j]<Val[j+1]) {
                        aux = V[j];
                        V[j] = V[j+1];
                        V[j+1] = aux;
                        aux2 = Val[j];
                        Val[j] = Val[j+1];
                        Val[j+1] = aux2;
                    }
                }
            }
        }
        if (x>0) printf("\n");
        for (i=0; i<256; i++) {
            if (V[i]!=0) printf("%d %d\n", Val[i], V[i]);
        }
        x++;
    }
}
