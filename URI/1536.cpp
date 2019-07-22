#include <stdio.h>

main ()
{
    int N, M, V, T1, T2, i, M0, V0, v1, v2;
    char a;
    scanf("%d", &N);

    for (i=0; i<N; i++) {
        T1=0, T2=0, v1=0, v2=0;
        scanf("%d %c %d", &M, &a, &V0);
        T1+= M;
        T2+= V0;
        if (M > V0) {
            v1++;
        }
        else if (M < V0) {
            v2++;
        }
        scanf("%d %c %d", &V, &a, &M0);
        T1+= M0;
        T2+= V;
        if (M0 > V) {
            v1++;
        }
        else if (M0 < V) {
            v2++;
        }
        if (v1 > v2) {
            printf("Time 1\n");
        }
        else if (v1 < v2) {
            printf("Time 2\n");
        }
        else if (v1 == v2) {
            if (T1-T2 > T2-T1) {
                printf("Time 1\n");
            }
            else if (T1-T2 < T2-T1) {
                printf("Time 2\n");
            }
            else if (T1 == T2) {
                if (M0 > V0) {
                    printf("Time 1\n");
                }
                else if (M0 < V0) {
                    printf("Time 2\n");
                }
                else {
                    printf("Penaltis\n");
                }
            }
        }
    }
}
