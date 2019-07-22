#include <stdio.h>
#include <math.h>
#define PI 2.0*acos(0.0)
main ()
{
    double A, I, II, III;

    while (scanf("%lf", &A) != EOF) {
        I = A*A*(1-sqrt(3)+PI/3);
        II = A*A*(2*sqrt(3)-4+PI/3);
        III = A*A*(4-2*PI/3-sqrt(3));
        printf("%.3F %.3F %.3F\n", I, II, III);
    }
}
