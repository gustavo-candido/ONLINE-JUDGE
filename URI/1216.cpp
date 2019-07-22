#include <stdio.h>

main ()
{
    char nome[1000];
    int i=0;
    double med, D, DT=0;

    while (gets(nome)) {
            i++;
        scanf("%lf", &D);
        getchar();
        DT = DT + D;
    }
    med = DT / i;
    printf("%.1f\n", med);
}