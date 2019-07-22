#include <stdio.h>

int main ()
{
    int N, x[5000], soma;

    while(scanf("%d", &N)) {
        if(!N) break;
        for (int i=0; i<N; i++) {
            scanf("%d", &x[i]);
        }
        soma=10;
        for (int i=0; i<N-1; i++) {
            if (x[i+1] - x[i] > 10) soma+=10;
            else soma+=x[i+1] - x[i];
        }

        printf("%d\n", soma);
    }
}
