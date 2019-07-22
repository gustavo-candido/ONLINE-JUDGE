#include <stdio.h>

main ()
{
    int N, M, A, B, i, j, h, k;
    char box[100][100];

    while (scanf("%d %d", &N, &M) != EOF)  {
            getchar();
        if (N==M && M==0) {
            break;
        }
        else {
           for (i=0; i<N; i++) {
                for (j=0; j<=M; j++) {
                    scanf("%c", &box[i][j]);
                }
           }
           scanf("%d %d", &A, &B);
           A/=N;
           B/=M;

           for (i=0; i<N; i++) {
                for (h=0; h<A; h++) {
                    for (j=0; j<M; j++) {
                        for (k=0; k<B; k++) {
                            printf("%c", box[i][j]);
                        }
                    }
                printf("\n");
                }
           }
        }
        printf("\n");
    }
}
