#include <stdio.h>
#include <stdlib.h>

typedef struct graf {
    int V, *grau, **aresta, *peso, *AUX;
} graf;

graf *cria (int V, int A) {
    graf *grf = (graf*) malloc(sizeof(int));
    grf->V = V+1;
    grf->grau = (int*) calloc(V+1, sizeof(int));
    grf->peso = (int*) calloc(V+1, sizeof(int));
    grf->AUX = (int*) calloc(V+1, sizeof(int));
    grf->aresta = (int**) calloc(V+1, sizeof(int*));
    for (int i=0; i<=V; i++) {
        grf->aresta[i] = (int*) calloc(A, sizeof(int));
        grf->AUX[i] = i;
    }
    return grf;
}

void insere (graf *grf, int ori, int dest) {
    grf->aresta[dest][grf->grau[dest]] = ori;
    grf->grau[dest]++;
}

void dfs (graf *grf, int ini, int *visitado, int cont, int *yng) {
    visitado[ini] = cont;
    for (int i=0; i<grf->grau[ini]; i++){
        if (visitado[grf->aresta[ini][i]] == 0) {
            if (grf->peso[grf->aresta[ini][i]] < *yng) {
                *yng = grf->peso[grf->aresta[ini][i]];
            }
            dfs(grf, grf->aresta[ini][i], visitado, cont+1, yng);
        }
    }
}

void DIGRAPHdfs(graf *grf, int ini) {
    int cont=1, yng = 10000, *visitado = (int*) calloc(grf->V+1, sizeof(int));
    for (int i=1; i<grf->V+1; i++) {
        if (visitado[ini]==0) {
            if (grf->grau[grf->AUX[ini]] > 0 ) {
                dfs(grf, grf->AUX[ini], visitado, cont, &yng);
            }
        }
    }
    if (yng==10000)printf("*\n");
    else printf("%d\n", yng);
}

void libera (graf *grf) {
    for (int i=0; i<grf->V; i++) {
        free(grf->aresta[i]);
    }
    free(grf->aresta);
    free(grf->grau);
    free(grf->peso);
    free(grf->AUX);
    free(grf);
}

void troca (graf *grf, int A, int B) {
    int aux;
    aux = grf->peso[grf->AUX[A]];
    grf->peso[grf->AUX[A]] = grf->peso[grf->AUX[B]];
    grf->peso[grf->AUX[B]] = aux;
    aux = grf->AUX[A];
    grf->AUX[A] = grf->AUX[B];
    grf->AUX[B] = aux;
}

int main ()
{
    int V, A, I, ori, dest, ini;
    graf *grf;
    char aux;
    while(scanf("%d %d %d", &V, &A, &I)!=EOF) {
        grf = cria(V, A);
        for (int i=1; i<=V; i++) {
            scanf("%d", &grf->peso[i]);
        }
        for (int i=0; i<A; i++) {
            scanf("%d %d", &ori, &dest);
            insere(grf, ori, dest);
        }

        for (int i=0; i<I; i++) {
            getchar();
            scanf("%c", &aux);
            if (aux == 'P') {
                scanf("%d", &ini);
                DIGRAPHdfs(grf, ini);
            }
            else if (aux == 'T') {
                scanf("%d %d", &ori, &dest);
                troca(grf, ori, dest);
            }
        }
    }
}
