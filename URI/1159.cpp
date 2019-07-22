#include <stdio.h>
main ()
{
    int X, A=1, S=0;
    while (1) {
        scanf ("%d", &X);
        if (X==0) {
            break;
        }
        while (A<=5) {
        if (X%2 == 0) {
            S = S + X;
            A++;
        }
        X++;
    }
    printf ("%d\n", S);
    S = 0;
    A = 1;
}
}