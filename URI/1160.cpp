#include <stdio.h>

main ()
{
    int z, c=0, PA, pa, PB, pb, A;
    float G1, G2;
    scanf("%d", &z);

    while (c<z) {
        scanf("%d %d %f %f", &PA, &PB, &G1, &G2);
        A = 0;

       while (PA <= PB) {
        pa = PA * G1 / 100;
        PA = PA + pa;
        pb = PB * G2 / 100;
        PB = PB + pb;
        A++;
        if (A>100) {
            printf("Mais de 1 seculo.\n");
            break;
        }
       }

        if (A<=100) {
            printf("%d anos.\n", A);
        }
        c++;
    }
}
