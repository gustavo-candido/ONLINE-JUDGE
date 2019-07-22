#include <stdio.h>

main ()
{
    int k, M, N, i, X, Y;

    while (scanf("%d", &k) != EOF) {
        if (k==0) {
            break;
        }
        else {
            scanf("%d %d", &N, &M);

            for (i=0; i<k; i++) {
                scanf("%d %d", &X, &Y);

                if (X==N || Y==M) printf("divisa\n");
                else if (X<N && Y>M) printf("NO\n");
                else if (X>N && Y>M) printf("NE\n");
                else if (X>N && Y<M) printf("SE\n");
                else if (X<N && Y<M) printf("SO\n");
            }
        }
    }
}