#include <stdio.h>
#include <stdlib.h>

main()
{
    int NC, C, N, c, *pow, *w, **box, R, K;

    scanf("%d", &NC);
    for (C=0; C<NC;C++) {
        scanf("%d", &N);
        pow = (int*) malloc((N+1)*sizeof(int));
        w = (int*) malloc((N+1)*sizeof(int));

        for (c=1; c<=N; c++) {
            scanf("%d %d", &pow[c], &w[c]);
        }

        scanf("%d %d", &K, &R);
        box = (int**)calloc(N+1 , sizeof(int*));

        for (c=0; c<=N; c++)
            box[c] = (int*) calloc(K+1, sizeof(int));

        for (c=1; c<=N; c++) {
            for (int j=1; j<=K; j++) {
                if (j < w[c]) box[c][j] = box[c-1][j];
                else {
                    if (box[c-1][j-w[c]]+pow[c] >= box[c-1][j])box[c][j] = box[c-1][j-w[c]]+pow[c];
                    else box[c][j] = box[c-1][j];
                }
            }
        }
        if (box[N][K] >= R) printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    }
}