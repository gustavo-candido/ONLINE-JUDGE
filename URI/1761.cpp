#include <stdio.h>
#include <math.h>
#define PI  3.141592654

main ()
{
    double A, B, C, H;

    while(scanf("%lf %lf %lf", &A, &B, &C) != EOF) {
        H = tan(A*PI/180)*B;
        H = (H+C) * 5;
        printf("%.2F\n", H);
    }
}
