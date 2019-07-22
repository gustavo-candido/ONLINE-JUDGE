#include <stdio.h>
#include <string.h>

main ()
{
    int N, c, M, i, cmp;
    char A[150][50];
    scanf("%d", &N);
    for (c=0; c<N; c++) {
        scanf("%d", &M);
        getchar();
        for (i=0; i<M; i++) {
            scanf("%s", A[i]);
        }
        for (i=1; i<M; i++) {
            cmp = strcmp(A[0], A[i]);
            if (cmp != 0) break;
        }
        if (cmp != 0) printf("ingles\n");
        else printf("%s\n", A[0]);
    }
}