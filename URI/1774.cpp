#include <stdio.h>
#include <stdlib.h>

typedef struct vertex{
    int cost, ori, dest;
} vertex;

int compare(const void *X, const void *Y) {
    return((*(vertex*)X).cost - (*(vertex*)Y).cost);
}

int find (int x, int *parent) {
    if (parent[x]==x) return x;
    else return find(parent[x], parent);
}

 void uni (int x, int y, int *parent) {
    parent[find(x, parent)] = find(y, parent);
}

int compara(int x, int y, int *parent) {
    if (find(x, parent) == find(y, parent)) return 1;
    else return 0;
}
int main ()
{
    vertex *grf;
    int mst, V, A, *parent;

    scanf("%d %d", &V, &A);
    parent = (int*) malloc(sizeof(int)*(A+1));

    for(int i=0; i<=V; i++)
        parent[i] = i;

    grf = (vertex*) malloc((A+1)*sizeof(vertex));

    for(int i=0; i<A; i++) {
        scanf("%d %d %d", &grf[i].ori, &grf[i].dest, &grf[i].cost);
    }
    qsort(grf, A, sizeof(vertex), compare);
    mst=0;
    for (int i=0; i<A; i++) {
        if (compara(grf[i].ori, grf[i].dest, parent) == 0) {
            mst+= grf[i].cost;
            uni(grf[i].ori, grf[i].dest, parent);
        }
    }
    printf("%d\n", mst);
    free(grf);
    free(parent);
}

