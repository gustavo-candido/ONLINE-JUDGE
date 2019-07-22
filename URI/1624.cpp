#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main ()
{
    int N, *prod, *peso, **box, max;

    while(scanf("%d", &N)) {
        if(!N)break;
        prod = (int*) malloc(N*sizeof(int));
        peso = (int*) malloc(N*sizeof(int));
        for (int i=0; i<N; i++) {
            scanf("%d %d", &prod[i], &peso[i]);
        }
        scanf("%d", &max);
        box = (int **) malloc((N+1)*sizeof(int*));
        for (int i=0; i<=N; i++) {
            box[i] = (int*) calloc(max+1, sizeof(int));
        }
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=max; j++) {
                if (j < peso[i-1]) box[i][j] = box[i-1][j];
                else box[i][j] = fmax(box[i-1][j], box[i-1][j-peso[i-1]]+prod[i-1]);
            }
        }
        printf("%d\n", box[N][max]);
        for (int i=0; i<=N; i++) {
            free(box[i]);
        }
        free(box);
    }
}
