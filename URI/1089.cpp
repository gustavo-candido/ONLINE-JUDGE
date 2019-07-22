#include <stdio.h>

main ()
{
    int N, i, aux[20000], pic;

    while (scanf("%d", &N) != EOF) {
        if (N==0) break;
        pic=0;
        for (i=0; i<N; i++) {
            scanf("%d", &aux[i]);
            }
            aux[N] = aux[0];
            aux[N+1] = aux[1];
        for (i=1; i<=N; i++) {
            if ((aux[i]>aux[i-1] && aux[i]>aux[i+1]) || (aux[i]<aux[i-1] && aux[i]<aux[i+1])) {
                pic++;
            }
        }
        printf("%d\n", pic);

    }
}