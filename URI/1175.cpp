#include <stdio.h>
main()
{
    int N[20], i=0, j=19, Y;
    for (j=19; j>=0; j--)
     {
        scanf("%d", &N[j]);
     }
    for (i=0; i<20; i++) {
        N[j] = N[i];
        Y = N[j];
        printf("N[%d] = %d\n", i, Y);
    }
}