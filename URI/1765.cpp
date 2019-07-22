#include <stdio.h>
 
main ()
{
    int N, c, Q;
    double A, B, area;
    while (scanf("%d", &N) != EOF) {
        if (N == 0) break;
 
        for (c=1; c<=N; c++) {
            scanf("%d %lf %lf", &Q, &A, &B);
            area = ((A+B)*5/2) * Q;
            printf("Size #%d:\n", c);
            printf("Ice Cream Used: %.2F cm2\n", area);
        }
        printf ("\n");
    }
}