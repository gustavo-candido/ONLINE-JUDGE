#include <bits/stdc++.h>
#define _m 10005
using namespace std;

typedef vector<int> vi;
vector<vi> grf;
int vis[_m], V, A;
bool f;

void dfs(int u) {
    vis[u] = 1;
    if(f) return;
    for(int i=0; i<(int)grf[u].size(); i++) {
        int v = grf[u][i];
        if(vis[v] == 1) {
            f = true;
            break;
        }
        if(vis[v] == 0) dfs(v);
    }
    vis[u] = 2;
}
int main()
{
    int t, o, d;

    scanf("%d", &t);

    while(t--) {
        grf.clear();
        scanf("%d %d", &V, &A);
        grf.resize(V);
        memset(vis, 0, sizeof(int)*V);
        for(int i=0; i<A; i++){
            scanf("%d %d", &o, &d); o--, d--;
            grf[o].push_back(d);
        }
        f = false;
        for(int i=0; i<V; i++) {
            if(vis[i] == 0)dfs(i);
            if(f)break;
        }
        printf("%s\n", (f == true)?"SIM":"NAO");
    }
}
