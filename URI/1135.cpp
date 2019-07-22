#include <bits/stdc++.h>  
#define msb(x) __builtin_clz(1) - __builtin_clz(x)
#define ff first
#define ss second
using namespace std;

typedef pair<int,long long> ii;
typedef vector<ii> vii;

const int N = 200005, LOG = 20;

int n, ocur[N], depth[N], table[N][LOG];
long long  w[N];
vector<int> euler; // [2*N]
vector<vii> grf;

void dfs(int u, int p, int h) {
    depth[u] = h;
    ocur[u] = euler.size();
    euler.push_back(u);

    for(ii v:grf[u]) {
        if(v.ff == p) continue;
        w[v.ff] = w[u] + v.ss;
        dfs(v.ff, u, h+1);
        euler.push_back(u);
    }
}

int lca(int l, int r) {
    l = ocur[l];
    r = ocur[r];
    if(l>r) swap(l,r);
    int bit = msb(r-l+1);
  
    if(depth[table[l][bit]] < depth[table[r-(1<<bit)+1][bit]]) return table[l][bit];
    return table[r-(1<<bit)+1][bit];
}

long long get_dis(int u, int v) {
    return w[u] + w[v] - 2 * w[(lca(u,v))];
}

int main()
{   
    while(scanf("%d", &n) && n) {
        grf.clear();
        euler.clear();
        grf.resize(n);


        for(int o=1; o<n; o++) {
            int d; scanf("%d", &d);
            int dist; scanf("%d", &dist);
            grf[o].push_back({d,dist});
            grf[d].push_back({o,dist});
        }

        memset(ocur, -1, sizeof ocur);

        w[0] = 0;
        dfs(0,-1, 1);

        for(int i=0; i<(int)euler.size(); i++) table[i][0] = euler[i];

        for(int j=1; (1<<j)<=(int)euler.size(); j++) {
            for(int i=0; i+(1<<j)<=(int)euler.size(); i++) {
                if(depth[table[i][j-1]] < depth[table[i+(1<<(j-1))][j-1]]) table[i][j] = table[i][j-1];
                else table[i][j] = table[i+(1<<(j-1))][j-1];
            }
        }

        int q; scanf("%d", &q);

        for(int i=0; i<q; i++) {
            int u; scanf("%d", &u);
            int v; scanf("%d", &v);
            if(i) putchar(' ');
            printf("%lld", get_dis(u,v));  
        }
        putchar('\n');
    }
}


