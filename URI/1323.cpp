#include <stdio.h>

main ()
{
    int N, i;
    long long int box;

    while (scanf("%d", &N) != EOF) {
        if (N ==0) break;

        else {
                box=0;
            for (i=1; i<=N; i++) {
                box = box + (i*i);
            }

            printf("%lld\n", box);
        }
    }
}