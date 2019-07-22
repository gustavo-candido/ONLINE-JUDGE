#include <stdio.h>
main ()
{
    int x, y, z, a, b, c;
    scanf ("%d %d %d", &x, &y, &z);
    if (x>y && x>z && y>z) {
        a = x;
        b = y;
        c = z;
    } else if (x>y && x>z && z>y) {
        a = x;
        c = y;
        b = z;
    } else if (y>x && y>z && x>z) {
        b = x;
        a = y;
        c = z;
    } else if (y>x && y>z && z>x) {
        c = x;
        a = y;
        b = z;
    } else if (z>x && z>y && x>y) {
        b = x;
        c = y;
        a = z;
    } else if (z>x && z>y && y>x) {
        c = x;
        b = y;
        a = z;
    }
    printf("%d\n%d\n%d\n", c, b, a );
    printf("\n");
    printf("%d\n%d\n%d\n", x, y, z );
}