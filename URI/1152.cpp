#include <stdio.h>
#include <stdlib.h>

typedef struct vertex{
    int cost, ori, dest;
} vertex;

int compara(int x, int y, int *parent);
int find (int x, int *parent);
void uni (int x, int y, int *parent);

int compare(const void *X, const void *Y) {
    return((*(vertex*)X).cost - (*(vertex*)Y).cost);
}

int main ()
{
    vertex *grf;
    int mst, tot, V, A, *parent;
    while(scanf("%d %d", &V, &A)) {
        if (V==0 && A==0) break;

        parent = (int*) malloc(sizeof(int)*A);
        for(int i=0; i<V; i++)
            parent[i] = i;
        grf = (vertex*) malloc(A*sizeof(vertex));
        for(int i=0; i<A; i++) {
            scanf("%d %d %d", &grf[i].ori, &grf[i].dest, &grf[i].cost);
        }
        qsort(grf, A, sizeof(vertex), compare);
        mst=tot=0;
        for (int i=0; i<A; i++) {
            if (compara(grf[i].ori, grf[i].dest, parent) == 0) {
                mst+= grf[i].cost;
                uni(grf[i].ori, grf[i].dest, parent);
            }
            tot+=grf[i].cost;
        }
        printf("%d\n", tot-mst);
        free(grf);
        free(parent);
    }
}

void uni (int x, int y, int *parent) {
    parent[find(x, parent)] = find(y, parent);
}

int find (int x, int *parent) {
    if (parent[x]==x) return x;
    else return find(parent[x], parent);
}

int compara(int x, int y, int *parent) {
    if (find(x, parent) == find(y, parent)) return 1;
    else return 0;
}
