#include <stdio.h>
main ()
{
    int X, Y, A=1, S=0, Z, T=1;
    scanf ("%d", &Z);
    while (T<=Z) {
    scanf ("%d %d", &X, &Y);
    while (A<=Y) {
        if (X%2 != 0) {
            S = S + X;
            A++;
        }
        X++;
    }
printf("%d\n", S);
S = 0;
A = 1;
T++;
}
}