#include <stdio.h>
#include <stdlib.h>

typedef struct graf {
    int V, *grau, **aresta;
}graf;

int compara (const void *a, const void *b) {
    return( *(int*)a - *(int*)b);
}

graf *cria (int V) {
    graf *grf = (graf*) malloc(sizeof(graf));
    grf->V = V;
    grf->grau = (int*) calloc(V, sizeof(int));
    grf->aresta = (int**) calloc(V, sizeof(int*));
    for (int i=0; i<V; i++)
        grf->aresta[i] = (int*) calloc (V*V, sizeof(int));
    return grf;
}

void insere (graf *grf, char x, char y) {
    int ori, dest;
    ori = ((int)x)-97;
    dest = ((int)y)-97;
    grf->aresta[ori][grf->grau[ori]] = dest;
    grf->aresta[dest][grf->grau[dest]] = ori;
    grf->grau[ori]++;
    grf->grau[dest]++;
}

void dfs (graf *grf, int ini, int *visitado, int cont) {
    visitado[ini] = cont;
    for (int i=0; i<grf->grau[ini]; i++) {
        if (visitado[grf->aresta[ini][i]] == 0) {
            dfs(grf, grf->aresta[ini][i], visitado, cont);
        }
    }
}

void DIGRAPHdfs (graf *grf, int ini, int *visitado) {
    int cont = 1;
    for (int i=0; i<grf->V; i++) {
        if (visitado[i] == 0) {
            dfs(grf, i, visitado, cont);
            for (int j=0; j<grf->V; j++) {
                if (visitado[j] == cont) printf("%c,", j+97);
            }
            printf("\n");
            cont++;
        }
    }
    printf("%d connected components\n", cont-1);
}

void libera (graf *grf) {
    for (int i=0; i<grf->V; i++) {
        free(grf->aresta[i]);
    }
    free(grf->aresta);
    free(grf->grau);
    free(grf);
}
int main ()
{
    graf *grf;
    int N, V, A, *x;
    char ori, dest;

    scanf("%d", &N);

    for (int c=0; c<N; c++) {
        scanf("%d %d", &V, &A);
        getchar();
        grf = cria(V);
        x = (int*) calloc(V, sizeof(int));
        for (int i=0; i<A; i++) {
            scanf("%c %c", &ori, &dest);
            getchar();
            insere(grf, ori, dest);
        }
        for (int i=0; i<V; i++) {
            qsort(grf->aresta[i], grf->grau[i], sizeof(int), compara);
        }
        printf("Case #%d:\n", c+1);
        DIGRAPHdfs(grf, 0, x);
        printf("\n");
        libera(grf);
        free(x);
    }
}
