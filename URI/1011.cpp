#include <stdio.h>
main ()
{
    int R;
    double Volume, pi = 3.14159;
    scanf ("%d", &R);
    Volume =  (4/3.0) * pi * R * R * R;
    printf("VOLUME = %.3f\n", Volume);
}
