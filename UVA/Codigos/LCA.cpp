#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

vector<vii> grf;
int N, K, M, lca[100005][20], h[100005];
ii path[100005][20];

void dfs(int u, int ult, int dist) {
     lca[u][0] = ult;
    path[u][0].F = dist;
    path[u][0].S = dist;

    for(int i=1; i<M; i++) {
         lca[u][i] = lca[lca[u][i-1]][i-1];
        path[u][i].F = min(path[u][i-1].F, path[lca[u][i-1]][i-1].F);
        path[u][i].S = max(path[u][i-1].S, path[lca[u][i-1]][i-1].S);
    }

    int v, w;

    for(int i=0; i<(int)grf[u].size(); i++) {
        v = grf[u][i].F, w = grf[u][i].S;
        if(v == ult) continue;
        h[v] = h[u] + 1;
        dfs(v, u, w);
    }
    return;
}

ii get_lca(int a, int b) {
    if(h[a] < h[b]) swap(a,b);

    int d = h[a] - h[b];
    int mini = path[a][0].F, maxi = path[a][0].S;

    for(int i = M-1; i >= 0; i--) {
        if(d & (1 << i)){
            mini = min(mini, path[a][i].F);
            maxi = max(maxi, path[a][i].S);
            a = lca[a][i];
        }
    }

    if(a == b) return ii(mini, maxi);

    for(int i = M-1; i >= 0; i--) {
        if(lca[a][i] != lca[b][i]) {
            mini = min(mini, path[a][i].F, path[b][i].F);
            maxi = max(maxi, path[a][i].S, path[b][i].S);
            a = lca[a][i];
            b = lca[b][i];
        }

    }
    mini = min(mini, path[a][0].F, path[b][0].F);
    maxi = max(maxi, path[a][0].S, path[b][0].S);
    return ii(mini, maxi);
}

int main()
{
    int o, d, p;
    scanf("%d", &N);
    grf.resize(N);
    M = log2(N);
    h[0] = 0;
    for(int i=1; i<N; i++) {
        scanf("%d %d %d", &o, &d, &p); o--, d--;
        grf[o].push_back(ii(d,p));
        grf[d].push_back(ii(o,p));
    }
    dfs(0, 0, 0);

    scanf("%d", &K);
    ii ans;

    while(K--) {
        scanf("%d %d", &o, &d);
        ans = get_lca(--o, --d);
        printf("%d %d\n", ans.F, ans.S);
    }
}
