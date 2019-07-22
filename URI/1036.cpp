#include <stdio.h>
#include <math.h>
main ()
{
    float A,B,C;
    scanf ("%f %f %f", &A, &B, &C);
    if (A==0)
    {
        printf ("Impossivel calcular\n");
    } else {
     float delta = (B*B) - (4* A * C);
     if (delta < 0) {
        printf ("Impossivel calcular\n");
     } else {
     float R1, R2;
    R1 = (-B + sqrt (delta)) / (2 * A);
    R2 = (-B - sqrt (delta)) / (2 * A);
    printf ("R1 = %.5f\n", R1);
    printf ("R2 = %.5f\n", R2);
    }
}
}