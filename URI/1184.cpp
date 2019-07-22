#include <stdio.h>

main ()
{
    float matriz [12] [12], Soma = 0, Media = 0;
    int i, j;
    char O;
    scanf("%c ", &O);

        for (i=0; i<12; i++) {
            for (j=0; j<12; j++) {
                scanf ("%f", &matriz [i] [j]);
            }
        }
        for (i=0; i<12; i++) {
            for (j=0; j<12; j++) {
                    if (j<i) {
                Soma = Soma + matriz[i][j];
                    }
            }
        }
        if (O == 'S') {
            printf ("%.1f\n", Soma);
        }
        if (O == 'M') {
            Media = Soma / 66;
            printf ("%.1f\n", Media);
        }
}