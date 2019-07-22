#include <stdio.h>
#include <math.h>

main ()
{
    int A, B, C, med;
    while (scanf("%d", &A) != EOF) {
        if (A==0) {
            break;
        }
        else {
            scanf("%d %d", &B, &C);
            med = sqrt(A * B * 100 / C);
            printf("%d\n", med);
        }
    }
}
