#include <stdio.h>

main ()
{
    long long int A, B, c;

    while (scanf("%lld %lld", &A, &B) != EOF) {
    c = A ^ B;

    printf("%lld\n", c);
    }
}
