#include <stdio.h>

main ()
{
    int L, R;
    while (scanf("%d %d", &L, &R) != EOF) {
        if (L==0 & R==0) {
            break;
        }
        else {
            printf ("%d\n", L + R);
        }
    }
}