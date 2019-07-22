#include <stdio.h>
#include <stdlib.h>

struct NUM{
        int num;
        int mod;
};
typedef struct NUM numero;

int compara (const void *a, const void *b) {
        numero A, B;
        A = *(numero*)a;
        B = *(numero*)b;
        if (A.mod>B.mod) {
             return 1;
        }
        else if (A.mod<B.mod) {
             return -1;
        }
        else if (A.mod == B.mod) {
                if ((A.num%2==0 && B.num%2!=0) || (A.num%2!=0 && B.num%2==0)) {
                        if (A.num%2!=0) return -1;
                        else return 1;
                }
                else if (A.num%2==0 && B.num%2==0) {
                        if (A.num < B.num) return -1;
                        else return 1;
                }
                else if (A.num%2!=0 && B.num%2!=0) {
                        if (A.num > B.num) return -1;
                        else return 1;
                }
        }

}
main()
{
        numero teste[100000];
        int N, M, x, y, z;
        while(scanf("%d %d", &N, &M) != EOF){
                printf("%d %d\n", N, M);
                if (N==0 && M==0) break;
                for(x=0; x<N; x++){
                        scanf("%d", &teste[x].num);
                        teste[x].mod = teste[x].num%M;
                }
                qsort(teste, N, sizeof(numero), compara);
                for(x=0; x<N; x++){
                        printf("%d\n", teste[x].num);
                }
        }
}
