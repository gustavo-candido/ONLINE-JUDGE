#include <stdio.h>
#include <stdlib.h>
main ()
{
    int NC, C, N, c, *p;

    scanf("%d", &NC);

    for (C=0; C<NC; C++) {
        scanf("%d", &N);
        p = (int*) malloc (N*sizeof(int));
        for (c=0; c<N; c++) {
            scanf("%d", &p[c]);
        }
        printf("Case %d: %d\n", C+1, p[N/2]);
        free(p);
    }
}
