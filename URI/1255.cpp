#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
main ()
{
    int N, *V, maior;
    char A[250];
    scanf("%d ", &N);

    for (int i=0; i<N; i++) {
        V = (int*) calloc(300, sizeof(int));
        maior = 0;
        gets(A);
        for (int j=0; j<strlen(A); j++) {
            if ((A[j] >= 65 && A[j] <= 90) || (A[j] >= 97 && A[j] <= 122)) {
                V[tolower(A[j])]++;
                if (V[tolower(A[j])] > maior) maior = V[tolower(A[j])];
            }
        }
        for (int j=97; j<=122; j++) {
            if (V[j] == maior) printf("%c", j);
        }
        printf("\n");
    }
}
