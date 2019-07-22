#include <stdio.h>
#include <math.h>
main ()
{
    long long int i, h, d;
    while (scanf("%lld %lld", &h, &i) != EOF) {
        d = fabs(h - i);
        printf("%lld\n", d);
    }
}
