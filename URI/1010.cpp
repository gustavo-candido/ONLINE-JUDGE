#include <stdio.h>
main ()
{
int a, b;
scanf ("%d %d", &a, &b);
float A;
scanf("%f", &A);
int  c,d;
scanf ("%d %d", &c, &d);
float B;
scanf("%f", &B);
printf ("VALOR A PAGAR: R$ %.2f\n", (b*A) + (d * B) );
}
