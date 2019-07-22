#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int N = 502;

int n,m, dis[N][N], vis[N], dp[N];
vector<int> grf[N];

int spfa(int u) {
    deque<int> q;
    for(int i=0; i<=n; i++) dp[i]=INF;

    dp[u] = 0;
    q.push_front(u);

    while(q.size()) {
        u = q.front();
        vis[u] = 0;
        q.pop_front();

        for(auto v:grf[u]) {
            if(dp[u]+dis[u][v] < dp[v]) {
                dp[v] = dp[u]+dis[u][v];
                if(vis[v]) continue;
                else {
                    vis[v] = 1;
                    if(q.size() && dp[q.front()] < dp[v]) q.push_back(v);
                    else q.push_front(v);
                }
            }
        }
    }
}

int main()
{       
    memset(vis, 0, sizeof vis);
    while(scanf("%d %d", &n, &m) && n+m) {
        for(int i=0; i<=n; i++) {
            grf[i].clear();
            for(int j=0; j<=n; j++) dis[i][j]=INF;
        }

        while(m--){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            dis[a][b] = min(dis[a][b], c);
            if(dis[b][a] < INF) dis[a][b] = dis[b][a] = 0;
        }

        for(int i=0; i<=n; i++) 
            for(int j=0; j<=n; j++) 
                if(dis[i][j] < INF) grf[i].push_back(j);

        scanf("%d", &m);

        while(m--) {
            int a, b;
            scanf("%d %d", &a, &b);
            spfa(a);
            if(dp[b]== INF) puts("Nao e possivel entregar a carta");
            else printf("%d\n",dp[b]);
        }
        puts("");
    }
}
