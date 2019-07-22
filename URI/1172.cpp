#include <stdio.h>
main ()
{
    int X[10], i=0;
    for (i=0; i<10; i++) {
    scanf("%d", &X[i]);
    if (X[i]<=0) {
        X[i] = 1;
    }
    printf ("X[%d] = %d\n", i, X[i]);
}
}
