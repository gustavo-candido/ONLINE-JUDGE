#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> grf;
int V, A, root, p[55], cont[55], num[55], low[55], bridge, child, counter;

void dfs(int u) {
    low[u] = cont[u] = counter++;

    for(int i=0; i<(int)grf[u].size(); i++) {
        int v = grf[u][i];

        if(cont[v] == -1) {
            if(u == root) child++;

            p[v] = u;

            dfs(v);

            if(low[v] > cont[u]) bridge++;

            low[u] = min(low[v], low[u]);
        }
        else if(v != p[u]) low[u] = min(low[u], low[v]);
    }
}
int main()
{
    int o, d;

    while(scanf("%d %d", &V, &A) != EOF) {
            grf.clear();
            grf.resize(V);
            for(int i=0; i<A; i++) {
                scanf("%d %d", &o, &d);o--, d--;
                grf[o].push_back(d);
                grf[d].push_back(o);
            }

            memset(p, -1, sizeof p);
            memset(cont, -1, sizeof cont);
            memset(low, -1, sizeof low);
            bridge = 0;
            for(int i=0; i<V; i++) {
                if(cont[i] == -1) {
                    root = i;
                    child = 0;
                    counter = 0;
                    dfs(i);
                }
            }

            printf("%d\n", bridge);
    }
}

