#include <stdio.h>

main ()
{
    int N, c, X,x, Y, y, aux, cit=1;
    double all;

    while (scanf("%d", &N) != EOF) {
        if (N==0) break;
        int A[201] = {0}, B[201]={0};
        y=0;
        x=0;
        aux=0;
        for (c=0; c<N; c++) {
            scanf("%d %d", &X, &Y);
            A[Y/X]++;
            B[Y/X]+=X;
            x+=X;
            y+=Y;
        }
        if (cit>1) printf("\n");
        printf("Cidade# %d:\n", cit);
        for (c=0; c<201; c++) {
            if (A[c]!=0 && aux==0) {
                printf("%d-%d", B[c], c);
                aux++;
            }
            else if (A[c]!=0 && aux!=0) {
                printf(" %d-%d", B[c], c);
                aux++;
            }
        }
        printf("\n");
        all =  (int)((double)y*100 / x);
        printf("Consumo medio: %.2F m3.\n", all/100);
        cit++;
    }
}
