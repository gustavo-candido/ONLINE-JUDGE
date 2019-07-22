#include <stdio.h>

main ()
{
    int B, N, R[21], i, D, C, V;

    while (scanf("%d %d", &B, &N) != EOF) {
        if (B==0 && N==0) break;
        for (i=0; i<B; i++) {
            scanf("%d", &R[i]);
        }
        for(i=0; i<N; i++) {
            scanf("%d %d %d", &D, &C, &V);
            R[D-1]-=V;
            R[C-1]+=V;
        }
        for (i=0; i<B; i++) {
            if (R[i]<0) {
                printf("N\n");
                break;
            }
            else if (i+1==B) printf("S\n");
        }
    }
}