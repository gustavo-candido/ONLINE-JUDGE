#include <stdio.h>
#include <stdlib.h>
main ()
{
    int T, c, D, I, B, i, *x, Qi, j, ing, quant, total, max;

    scanf("%d", &T);
    for (c=0; c<T; c++) {
        scanf("%d %d %d", &D, &I, &B);
        x = (int*) malloc (sizeof(int)*I);
        for (i=0; i<I; i++) {
            scanf("%d", &x[i]);
        }
        max = 0;
        for (i=0; i<B; i++) {
            scanf("%d", &Qi);
            total = 0;
            for (j=0; j<Qi; j++) {
                scanf("%d %d", &ing, &quant);
                total+= (x[ing]*quant);
            }
            if (D/total > max) max = D/total;
        }
        printf("%d\n", max);
    }
}