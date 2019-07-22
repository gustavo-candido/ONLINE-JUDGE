#include <stdio.h>
main ()
{
    int N, I=1;
    float X, Y;
    scanf("%d", &N);
    for (I=1; I<=N; I++) {
        scanf("%f %f", &X, &Y);
        if (Y==0) {
            printf("divisao impossivel\n");
        }
   else if (Y!=0) {
    printf("%.1f\n", (X/Y));
    }
    }
}