#include <stdio.h>
#include <math.h>

main ()
{
    float pl, D, Q, P, A, B;

    while (scanf("%f", &Q) != EOF) {
        if (Q == 0) break;
        scanf("%f %f", &D, &P);
        A = floor(Q*P/Q);
        B = floor(Q*P/P);
        pl = floor((D * (Q*P)) / (A-B));
        if (pl == 1) printf("%.0f pagina\n", pl);
        else printf("%.0f paginas\n", pl);
    }
}