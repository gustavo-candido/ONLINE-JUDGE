#include <stdio.h>
#include <stdlib.h>

int MDC(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) return a;
    else return MDC(b, a % b);
}

main ()
{
    int N, D1, D2, N1, N2, d, i;
    char a, b, O;

    scanf("%d", &N);

    for (i=0; i<N; i++){
        scanf("%d %c %d %c %d %c %d", &N1, &a, &D1, &O, &N2, &b, &D2);
        if (O == '+') {
            N1 = (N1*D2 + N2*D1);
            D1 = (D1*D2);
        }
        else if (O == '-') {
            N1 = (N1*D2 - N2*D1);
            D1 = (D1*D2);
        }
        else if (O == '*') {
            N1 = (N1*N2);
            D1 = (D1*D2);
        }
        else if (O == '/') {
            N1 = (N1*D2);
            D1 = (N2*D1);
        }
        printf("%d/%d = ", N1, D1);
        d = MDC (N1, D1);
        N1 = N1/d;
        D1 = D1/d;
        printf("%d/%d\n", N1, D1);
    }
}