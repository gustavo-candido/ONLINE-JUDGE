#include <stdio.h>
#include <stdlib.h>
struct TIME {
    int camp=0, marc=0, rec=0, insc;
};
typedef struct TIME time;
int compara (const void *a, const void *b){
    time A, B;
    A = *(time*)a;
    B = *(time*)b;
    if (A.camp > B.camp) return -1;
    else if (A.camp < B.camp) return 1;
    else if (A.camp == B.camp) {
        if ((double)A.marc/A.rec > (double)B.marc/B.rec) return -1;
        else if ((double)A.marc/A.rec < (double)B.marc/B.rec) return 1;
        else if ((double)A.marc/A.rec == (double)B.marc/B.rec) {
            if (A.marc > B.marc) return 1;
            else if (A.marc < B.marc) return -1;
            else if (A.marc == B.marc) {
                if (A.insc < B.insc) return -1;
                else if (A.insc > B.insc) return 1;
            }
        }
    }
}
main ()
{
    int N, c, T1, P1, T2, P2, x=0;
    while (scanf("%d", &N) != EOF) {
        if (N==0) break;
        time teste[1000];
        for (c=0; c <(N-1)*N/2; c++) {
            scanf("%d %d %d %d", &T1, &P1, &T2, &P2);
            teste[T1-1].marc+=P1;
            teste[T1-1].rec+=P2;
            teste[T1-1].insc= T1;
            teste[T2-1].marc+=P2;
            teste[T2-1].rec+=P1;
            teste[T2-1].insc= T2;
            if (P1>P2) {
                teste[T1-1].camp+=2;
                teste[T2-1].camp+=1;
            }
            if (P1<=P2) {
                teste[T2-1].camp+=2;
                teste[T1-1].camp+=1;
            }
        }
        if (x>0) printf("\n");
        printf("Instancia %d\n", x+1);
        qsort(teste, N, sizeof(time), compara);
        for (c=0; c<N; c++) {
            printf("%d", teste[c].insc);
            if (c+1 != N) printf(" ");
            else printf("\n");
        }
        x++;
    }
}
