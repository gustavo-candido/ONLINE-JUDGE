#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int N, K, *V, x, i;

    while(scanf("%d %d", &N, &K)) {
        if (N == 0 && K == 0) break;
        V = (int*)calloc(150, sizeof(int));
        for (i=0; i<N; i++) {
            scanf("%d", &x);
            V[x]++;
        }
        for (i=0, x=0; i<101; i++) {
            if (V[i] >= K && V[i]!=0) x++;
        }
        printf("%d\n", x);
    }
}
