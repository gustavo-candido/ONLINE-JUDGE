#include <stdio.h>
main ()
{
float a, b, c;
int x;
scanf ("%f", &a);
if (a>=0 && a<= 400.00) {
x = 15;
} else if (a>=400.01 && a<= 800) {
x = 12;
} else if (a>=800.01 && a<= 1200) {
x = 10;
} else if (a>=1200.01 && a<= 2000) {
x = 7;
} else if (a>2000) {
x = 4;
}
c = a * x / 100;
b = a + c;
printf("Novo salario: %.2f\n", b );
printf("Reajuste ganho: %.2f\n", c );
printf("Em percentual: %d %\n", x );
}