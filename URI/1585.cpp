#include <stdio.h>
#include <math.h>

main ()
{
    int N, c=0;
    float x, y, z;

    scanf("%d", &N);

    while (c<N) {
        scanf("%f %f", &x, &y);
        z= floor(x * (y/2));
        printf("%.0f cm2\n", z);
        c++;
    }
}