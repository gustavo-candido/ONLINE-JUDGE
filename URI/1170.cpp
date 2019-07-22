#include <stdio.h>

main ()
{
    int N, i=0;
    float C;
    scanf("%d", &N);
    while (i<N) {
            int dias = 0;
            scanf("%f", &C);
            while (C>1) {
                C = C / 2;
                dias++;
            }
            printf("%d dias\n", dias);

        i++;
    }
}
