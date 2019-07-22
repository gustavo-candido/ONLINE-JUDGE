#include <stdio.h>
#include <math.h>

main ()
{
    int L, C, R1, R2, X;
    while (scanf("%d %d %d %d", &L, &C, &R1, &R2)) {
        if (!L && !C && !R1 && !R2) break;
        if (L < C) X = L;
        else X = C;
        if (2*R1 <= X && 2*R2 <= X) {
            if (hypot(L - R2 - R1, C - R2 - R1) >= R1+R2) printf("S\n");
            else printf("N\n");
        }
        else printf("N\n");
    }
}

