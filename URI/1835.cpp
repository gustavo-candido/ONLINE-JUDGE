#include<bits/stdc++.h>
using namespace std;

vector< vector<int> >grf;
int V, A, vis[2000];

void bfs(int ini) {
    queue<int>q;
    q.push(ini);
    vis[ini] = 1;

    while(q.size()) {
        int u = q.front();
        q.pop();

        for(int i=0; i<(int)grf[u].size(); i++){
            int v = grf[u][i];
            if(vis[v] == -1) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}


int main()
{
    int t, o, d;

    scanf("%d", &t);

    for(int C=1; C<=t; C++) {
        grf.clear();

        scanf("%d %d", &V, &A);

        grf.resize(V);

        for(int i=0; i<A; i++){
            scanf("%d %d", &o, &d); o--, d--;
            grf[o].push_back(d);
            grf[d].push_back(o);
        }
        memset(vis, -1, sizeof(int)*V);
        bfs(0);
        int ans=0;

        for(int i=0; i<V; i++) {
            if(vis[i] == -1) {
                bfs(i);
                ans++;
            }
        }

        if(ans == 0)printf("Caso #%d: a promessa foi cumprida\n", C);
        else printf("Caso #%d: ainda falta(m) %d estrada(s)\n", C, ans);
    }
}
