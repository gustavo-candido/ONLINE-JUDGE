#include <stdio.h>
main ()
{
    int X, Y,A, B, S=0;
    scanf ("%d %d", &X, &Y);
    if (X>Y) {
        A = X;
        B = Y;
    }
    if (X<Y) {
        A = Y;
        B = X;
    }
    int I = B+1;
    for (I=B+1; I<A; I++) {
        if (I%5 == 2 || I%5 == 3) {
           S = I;
    printf("%d\n",S);
        }
    }
}