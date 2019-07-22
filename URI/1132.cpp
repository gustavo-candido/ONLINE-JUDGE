#include <stdio.h>
main ()
{
    int X, Y, A, B, S=0;
    scanf ("%d %d", &X, &Y);
    if (X>Y) {
        A = X;
        B = Y;
    }
    if (X<Y) {
        A = Y;
        B = X;
    }
    int I = B;
    for (I=B; I<=A; I++) {
        if (I%13 != 0) {
           S = S + I;
        }
    }
    printf("%d\n",S);
}