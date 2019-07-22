#include <stdio.h>

main ()
{
    float matriz [12] [12], Soma = 0, Media = 0;
    int i, j, L;
    char T;
    scanf("%d ", &L);
    scanf("%c ", &T);

    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
            scanf("%f", &matriz[i] [j]);
        }
    }

    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
            if (L == i) {
                Soma = Soma + matriz [i] [j];
            }
        }
    }

    if (T == 'S') {
        printf ("%.1f\n", Soma);
    }
    if (T == 'M') {
        Media = Soma / 12;
        printf ("%.1f\n", Media);
    }
}