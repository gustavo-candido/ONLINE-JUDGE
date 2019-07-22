#include <stdio.h>
#include <string.h>

main ()
{
    int N, i, x;
    char A[100];
    scanf("%d", &N);
    getchar();
    for (N=N; N>0; N--) {
        gets(A);
        x=0;
        for (i=0; i<strlen(A); i++) {
            if (x==0 && A[i]>=97 && A[i]<=122) {
                printf("%C", A[i]);
                x=1;
            }
            if (A[i] == ' ') x=0;
        }
        printf("\n");
    }
}