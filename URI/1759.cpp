#include <stdio.h>

main ()
{
    int a, i;

    scanf("%d", &a);

    for (i=0; i<a; i++) {
        if (i==0) printf("Ho");
        if (i>0) printf(" Ho");
    }
    printf("!\n");
}