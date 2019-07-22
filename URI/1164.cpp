#include <stdio.h>
main ()
{
    int T, i=1,N, I, S=0;
    scanf ("%d", &T);
    while (T>=i) {
        scanf ("%d", &N);
        for (I=1; I<N; I++) {
        if (N%I==0) {
        S = S + I;
        }
    }
    if (S==N) {
        printf ("%d eh perfeito\n", N);
    }
    if (S!=N) {
        printf ("%d nao eh perfeito\n", N);
    }
    i++;
    S = 0;
}
}