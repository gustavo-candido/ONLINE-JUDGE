#include <stdio.h>
main ()
{
    int A=1, G=2, D=3, F=4, X;
    int a=0, g=0, d=0;
    while (1) {
        scanf("%d", &X);
        if (X<1 && X>4) {
            continue;
        }
        if (X==A) {
            a++;
        }
        if (X==G) {
            g++;
        }
        if (X==D) {
            d++;
        }
        if (X==F) {
            break;
        }
        }
    printf("MUITO OBRIGADO\n");
    printf("Alcool: %d\n", a);
    printf("Gasolina: %d\n", g);
    printf("Diesel: %d\n", d);
}


