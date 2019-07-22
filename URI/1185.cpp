#include <stdio.h>

main ()
{
    char O;
    int i, j, uh=11;
    float matriz[12][12], Soma=0, Media=0;

    scanf("%c ", &O);

    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
            if (j<uh) {
                Soma = Soma + matriz[i][j];
            }
        }
        uh--;
    }

    if (O == 'S') {
        printf ("%.1f\n", Soma);
    }

    if (O == 'M') {
        Media = Soma / 66;
        printf ("%.1f\n", Media);
    }
}
