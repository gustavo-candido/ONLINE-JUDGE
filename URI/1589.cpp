#include <stdio.h>
main()
{
    int R1, R2, T, i=1;
    scanf ("%d", &T);
    while (i<=T){
        scanf("%d %d", &R1, &R2);
        printf("%d\n", R1 + R2);
        i++;
    }
}