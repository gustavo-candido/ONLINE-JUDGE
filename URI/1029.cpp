#include <stdio.h>

int fib (int n) {
    int i=0;
    if (n==1) {
        i++;
        return 1;
    }
    if (n==0) {
        i++;
        return i;
    }
    else {
        i++;
        return fib(n-1) + fib(n-2);
    }
}
int FIB (int n) {
    if (n==1) {
        return 1;
    }
    if (n==0) {
        return 0;
    }
    else {
        return FIB(n-1) + FIB(n-2);
    }
}

main ()
{
    int N, c, x, nc, f;
    scanf("%d", &N);

    for (c=0; c<N; c++) {
        scanf("%d", &x);
        f = FIB(x);
        nc = fib(x);
        nc = nc + nc-2;
        printf("fib(%d) = %d calls = %d\n", x, nc, f);
    }
}