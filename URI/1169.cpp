#include <stdio.h>

main ()
{
    unsigned long long int N, X, c=0, g=1, kg, i=1;

    scanf("%llu", &N);

    while (c<N) {
            scanf("%llu", &X);
            if (X==64) {
                printf("1537228672809129 kg\n");
                break;
            }
            for (i=1, g=1;i<=X; i++) {
                g = g * 2;

            }
            kg = g / 12000;
            printf("%llu kg\n", kg);
        c++;
    }
}
