#include <stdio.h>
main ()
{
int N, i, X, Y, A, B,j=B, k=0;
scanf("%d", &N);
for (i=0; i<N; i++) {
    scanf("%d %d", &X, &Y);
    if (X>Y) {
        A = X;
        B = Y;
    }
    if (X<Y) {
        A = Y;
        B = X;
    }
    for (j=B+1; j<A; j++) {
        if (X==Y) {
        k = 0;
        break;
    }
        if (j%2 != 0) {
            k = k + j;
        }
    }
 printf("%d\n",k);
 k = 0;
        }
    }