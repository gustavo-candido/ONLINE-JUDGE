#include <stdio.h>
main()
{
    int  T, t=1, M;
    long long int N[61], i=0;
    scanf("%d", &T);
    while (t<=T) {
    for (i=0; i<61; i++) {
        if (i==0) {
            N[i] = 0;
        }
        if (i==1) {
            N[i] = 1;
        }
        if (i>1) {
            N[i] = N[i-1] + N[i-2];
        }
    }
    scanf("%d", &M);
    i = M;
    printf ("Fib(%lld) = %lld\n", i, N[i] );
    t++;
}
}