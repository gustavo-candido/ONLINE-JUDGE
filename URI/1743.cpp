#include <stdio.h>

main ()
{
    int A[5], B[5], i, j;

    for (i=0; i<5; i++) {
        scanf("%d", &A[i]);
    }
    for (i=0, j=0; i<5; i++) {
        scanf("%d", &B[i]);
        if (B[i]!=A[i]) j++;
    }
    if (j==5) printf("Y\n");
    else printf("N\n");

} 