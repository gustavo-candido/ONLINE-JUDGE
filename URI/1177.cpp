#include <stdio.h>
main ()
{
    int T, N[1000], i, j;
    scanf("%d", &T);
    for (i=0, j=0; i<1000; i++) {
        N[i] = j;
        j++;
        if (i%T==0) {
        j = 0;
        }
        printf("N[%d] = %d\n", i, j);
    }
}
