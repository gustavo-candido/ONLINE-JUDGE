#include <stdio.h>
#include <math.h>
main ()
{
    int A, B, C;
    double X;

    while (scanf("%d %d %d", &A, &B, &C) != EOF) {
        if (A==0 && B==0 && C==0)  break;
        X = A*B*C;
        X =pow (X,1.0/3.0);
        if (A==B && A==C) printf("%d\n", A);
        else printf("%d\n", (int)X);
    }
}
