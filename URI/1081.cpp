#include <stdio.h>
#include <stdlib.h>

typedef struct grafo {
    int V, *grau, **aresta;
} graf;

graf *cria (int V, int A);
void insere (graf *grf, int ori, int dest);
void busca (graf *grf, int ini, int *visitado, int cont);
void visitados (graf *grf, int ini, int *visitado);
int compara (const void *A, const void *B);

int main ()
{
    int N, c, ori, dest, V, A, *x, count=1;
    graf *teste;
    scanf("%d", &N);

    for (c=0; c<N; c++) {
        scanf("%d %d", &V, &A);
        teste = cria(V, A);
        x = (int*) calloc((V+1), sizeof(int));
        for (int i=0; i<A; i++) {
            scanf("%d %d", &ori, &dest);
            insere (teste, ori, dest);
        }
        for (int i=0; i<=V; i++) {
            qsort(teste->aresta[i], teste->grau[i], sizeof(int), compara);
        }
        printf("Caso %d:\n", count);
        visitados(teste, 0, x);
        count++;
    }
}

graf *cria (int V, int A) {
    graf *grf = (graf*) malloc (sizeof(graf));
    grf->grau = (int*) calloc ((V+1),sizeof(int));
    grf->V = V;
    grf->aresta = (int**) calloc ((V+1),sizeof(int*));
    for (int i=0; i<=V; i++) {
        grf->aresta[i] = (int*) calloc ((V+1),sizeof(int));
    }
    return grf;
}

void insere (graf *grf, int ori, int dest) {
    grf->aresta[ori][grf->grau[ori]] = dest;
    grf->grau[ori]++;
}

void busca (graf *grf, int ini, int *visitado, int cont) {
    int i, k;
    visitado[ini] = cont;
    for (i=0; i<grf->grau[ini]; i++) {
        for (int r=0; r<(cont*2); r++) printf(" ");
        printf("%d-%d", ini, grf->aresta[ini][i]);
        k=1;
        if (visitado[grf->aresta[ini][i]]==0) {
            k=0;
            printf(" pathR(G,%d)\n", grf->aresta[ini][i]);
            busca(grf, grf->aresta[ini][i], visitado, cont+1);
        }
        if(k==1) printf("\n");
    }
}

void visitados (graf *grf, int ini, int *visitado) {
    int i, cont = 1;
    for(i=0; i<grf->V; i++)
        visitado[i] = 0;
    for (i=0; i<=grf->V; i++) {
        if (visitado[i] == 0) {
            if(grf->grau[i]>0){busca(grf, i, visitado, cont); printf("\n");}
        }
    }
}

int compara (const void *A, const void *B) {
     return ( *(int*)A - *(int*)B );
}
