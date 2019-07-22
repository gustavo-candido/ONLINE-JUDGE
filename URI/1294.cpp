#include <stdio.h>
#include <math.h>
int main()
{
    double L, W, maior, menor;

    while(scanf("%lf %lf", &L, &W) != EOF) {
        maior =(W+L-sqrt(W*W-W*L+L*L))/6;
        if (L < W) menor = L/2.0;
        else menor = W/2.0;
        printf("%.3F 0.000 %.3F\n", maior, menor);
    }

}
