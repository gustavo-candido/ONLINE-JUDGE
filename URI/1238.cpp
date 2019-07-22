
#include <stdio.h>
#include <string.h>

main ()
{
    int N, c, i, tam, tam2;
    char A[100], B[100];

    scanf("%d", &N);

    for (c=0; c<N; c++) {
        scanf("%s %s", A, B);
        tam=strlen(A);
        tam2=strlen(B);
        i=0;
        if (tam>=tam2) {
            while (B[i] != '\0') {
                printf("%c", A[i]);
                printf("%c", B[i]);
                i++;
            }
            while (A[i] != '\0') {
                printf("%c", A[i]);
                i++;
            }
            printf("\n");
        }
        else {
            while (A[i] != '\0') {
                printf("%c", A[i]);
                printf("%c", B[i]);
                i++;
            }
            while (B[i] != '\0') {
                printf("%c", B[i]);
                i++;
            }
            printf("\n");
        }
    }
}