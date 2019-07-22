#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Lista {
    char num[250];
};
typedef struct Lista lista;

int compara (const void *a, const void *b) {
    return strcmp((*(lista*)a).num, (*(lista*)b).num);
}

int main ()
{
    int N, c, i, tot;
    lista *teste;

    while (scanf("%d ", &N) != EOF) {
        teste = (lista*) malloc(N*sizeof(lista));
        tot=0;
        for (c=0; c<N; c++) {
            scanf("%s", teste[c].num);
        }
        qsort(teste, N, sizeof(Lista), compara);
        for (c=0; c<N-1; c++) {
            i=0;
            while (teste[c].num[i] == teste[c+1].num[i]) {
                i++;
            }
            tot+=i;
        }
        printf("%d\n", tot);
        free(teste);
    }
}
