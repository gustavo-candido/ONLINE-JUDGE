#include <bits/stdc++.h>
#define _n 50005
#define _m 17
using namespace std;

typedef vector<int> vi;

vector<vi> grf;
int lca[_n][_m+1], c[_n], f[_n/2], s[_n/2], h[_n];
int V, A;

void dfs(int u, int ult) {
    lca[u][0] = ult;

    for(int i=1; i<=_m; i++) lca[u][i] = lca[lca[u][i-1]][i-1];

    for(int i=0; i<(int)grf[u].size(); i++) {
        int v = grf[u][i];

        if(v == ult) continue;

        h[v] = h[u]+1;
        dfs(v, u);
    }
}

int get_lca(int a, int b) {
    if(h[a] < h[b]) swap(a, b);
    int d = h[a] - h[b];


    for(int i=_m; i>=0; i--)
        if(d & (1<<i))  a = lca[a][i];

    if(a == b) return a;

    for(int i=_m; i>=0; i--)
    if(lca[a][i] != lca[b][i]){
        a = lca[a][i];
        b = lca[b][i];
    }
    return lca[a][0];
}

int get_dist(int a, int b) {
    return h[a] + h[b] -  2 * h[get_lca(a, b)];
}

int main()
{
    int o, d;
    scanf("%d", &V);

    memset(f, -1, sizeof(int)*((V+1)/2));
    for(int i=0; i<V; i++) {
            scanf("%d", &c[i]);c[i]--;
            if(f[c[i]] == -1) f[c[i]] = i;
            else  s[c[i]] = i;
    }

    grf.resize(V);

    for(int i=0; i<V-1; i++) {
        scanf("%d %d", &o, &d); o--; d--;
        grf[o].push_back(d);
        grf[d].push_back(o);
    }
    h[0] = 0;
    dfs(0,0);

    long long int ans = 0;

    for(int i=0; i<V/2; i++) ans+=get_dist(f[i], s[i]);


    printf("%lld\n", ans);
}
