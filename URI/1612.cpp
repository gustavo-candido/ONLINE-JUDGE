#include <stdio.h>
#include <math.h>

main ()
{
    int N, i, A;
    float B;
    scanf("%d", &N);

    for (i=0; i<N; i++) {
        scanf("%d", &A);
        if (A % 2 == 0) {
            printf("%d\n", A/2);
        }
        else {
            printf("%d\n", A/2+1);
        }
    }
}