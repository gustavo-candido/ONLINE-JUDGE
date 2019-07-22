#include <stdio.h>
#include <string.h>

main()
{
    int N, c=0, M, i, j, h, x=4;

    scanf ("%d", &N);

    while (c<N) {
            if (x>4) {
                printf("\n");
            }
            scanf ("%d", &M);
             unsigned long long int box[M][M], maior[M], tam[M], HAV;
             char esp[1000000], hav[1000000];
            for (i=0; i<M; i++) {
                for (j=0; j<M; j++) {
                    scanf("%llu", &box[i][j]);
                    box[i][j]*=box[i][j];

                        if (i==0) {
                            maior[j] = 0;
                        }

                        if (maior[j] < box[i][j]) {
                                maior[j] = box[i][j];
                        }
                }
            }
            for (i=0; i<M; i++) {
            sprintf(esp, "%llu", maior[i]);
            tam[i] = strlen(esp);
            }
            printf("Quadrado da matriz #%d:\n", x);
            for(i=0; i<M; i++) {
                    for (j=0; j<M; j++) {
                        sprintf(hav, "%llu", box[i][j]);
                        HAV = strlen(hav);
                        for (h=0; h<tam[j]-HAV; h++) {
                            printf(" ");
                        }
                        if (j == M-1) printf("%llu", box[i][j]);
                        else printf("%llu ", box[i][j]);
                    }
                    printf("\n");
                }
        c++;
        x++;
    }
}