#include <stdio.h>
#include <stdlib.h>

main ()
{
    long long int Y, Z;
    int N, c;
    double A, B, C, D, X;

    scanf("%d", &N);

    for (c=0; c<N; c++) {
        scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
        if (C>A) X=(double)(D-B)/(double)(C-A);
        else X = (double)(abs(D-B))/(double)(abs(C-A));
        Y = X;
        Z = (X-Y)*100;
        if (Z>9)printf("%lld,%lld\n", Y, Z);
        else printf("%lld,0%lld\n", Y, Z);
    }
}