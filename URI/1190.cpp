#include <stdio.h>
  
main ()
{
    int i, j, uh= 0, wo = 11;
    char O;
    double matriz[12][12], Soma=0, Media=0;
  
    scanf ("%c ", &O);
    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
            scanf("%lf", &matriz[i][j]);
        }
    }
  
    for (i=0; i<12; i++) {
        for (j=0; j<12; j++) {
                if (i<6 && j>wo) {
                    Soma = Soma + matriz[i][j];
                }
                if (i>5 && j>uh) {
                    Soma = Soma + matriz[i][j];
                }
        }
        uh++;
        wo--;
    }
  
    if (O == 'S') {
        printf ("%.1f\n", Soma);
    }
    if (O == 'M') {
        Media = Soma / 30;
        printf ("%.1f\n", Media);
    }
}