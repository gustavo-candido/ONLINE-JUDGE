#include <stdio.h>

main()
{
    int v, c;

    while (scanf("%d %d", &v, &c)!= EOF) {
        printf("%d\n", (v*c*2));
    }
}