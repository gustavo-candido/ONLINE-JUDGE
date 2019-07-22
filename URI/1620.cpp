#include <stdio.h>

int main ()
{
    double X, I, L;

    while (scanf("%lf", &L), L!=0) {
        I = 3 + (L-3)*2;
        X = (I-L)/L;
        printf("%.6F\n", X);
    }
}
