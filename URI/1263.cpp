#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main ()
{
    char A[150][100], *aux, B[7000], aux2;
    int i, x;
    bool a;

    while(gets(B) != NULL) {
        for (i=0; i<strlen(B); i++) {
            B[i] = tolower(B[i]);
        }
        aux = strtok(B, " ");
        strcpy (A[0], aux);
        i = 1;
        x = 0;
        a = true;
        while (aux != NULL) {
            aux = strtok(NULL, " ");
            if (aux != NULL)strcpy (A[i], aux);
            i++;
        }
        aux2 = A[0][0];
        for(int j=1; j<i; j++) {
            if (aux2 == A[j][0] && a==true) {
                x++;
                a = false;
            }
            else if (aux2 != A[j][0]) {
                aux2 = A[j][0];
                a = true;
            }
        }
        printf("%d\n", x);
    }
}
