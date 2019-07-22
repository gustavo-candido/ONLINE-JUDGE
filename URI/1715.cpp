#include <stdio.h>

main()
{
    int N, c, M, i, j, g, h=0;

    scanf("%d", &N);
    scanf("%d", &M);
    for (c=0; c<N; c++) {
        for (i=0, j=0; i<M; i++){
            scanf("%d", &g);
            if (g!=0) j++;
        }
        if (j == M) {h++;}
    }
    printf("%d\n", h);
}
