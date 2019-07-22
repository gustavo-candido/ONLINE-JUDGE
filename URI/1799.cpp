#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

map<string, int> m;
vector<vi> grf;
int V, A;

int bfs(int ini, int fim) {
    int dis[4005];
    queue<int> q;

    memset(dis, 0x3F3F3F3F, sizeof(int)*V);
    dis[ini] = 0;
    q.push(ini);

    while(q.size()) {
        int u = q.front(); q.pop();

        if(u == fim) return dis[u];

        for(int i=0; i<(int)grf[u].size(); i++) {
            int v = grf[u][i];
            if(dis[u]+1 < dis[v]) {
                dis[v] = dis[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    char o[20], d[20];
    scanf("%d %d", &V, &A);
    getchar();

    grf.resize(V);

    for(int i=0; i<A; i++) {
        scanf("%s %s", o, d);
        if(!m.count(o))m[o] = m.size()-1;
        if(!m.count(d))m[d] = m.size()-1;
        grf[m[o]].push_back(m[d]);
        grf[m[d]].push_back(m[o]);
    }

    printf("%d\n", bfs(m["Entrada"], m["*"]) + bfs(m["*"], m["Saida"]));
}
