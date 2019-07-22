#include <stdio.h>

int MDC(int a, int b) {
    if (b == 0) return a;
    else return MDC(b, a % b);
}

main ()
{
    int N, c, F1, F2, t;

    scanf("%d", &N);

    for (c=0; c<N; c++) {
        scanf("%d %d", &F1, &F2);
        t = MDC (F1, F2);
        printf("%d\n", t);
    }
}