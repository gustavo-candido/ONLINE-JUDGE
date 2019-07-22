#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int V;
vector< set<ii> > grf;
vi dis, p;
bitset<510>iq;
int sssp(int ori, int dest) {
    dis.clear();dis.assign(V, INF);
    p.clear();p.assign(V, -1);
    queue<int> q;
    int u, v, d;
    q.push(ori);
    dis[ori] = 0;
    iq[ori] = 1;
    while(q.size()){
        u = q.front(); q.pop(); iq[u] = 0;
        for(set<ii>::iterator i=grf[u].begin(); i!=grf[u].end(); i++) {
            v = i->first, d = i->second;
            if(dis[u]+d <= dis[v]) {
                p[v] = u;
                dis[v] = dis[u]+d;
                if(!iq[v]) {
                    iq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dis[dest];
}

void path(int dest) {
    if(p[dest] == -1) return;
    grf[p[dest]].erase(ii(dest, dis[dest]-dis[p[dest]]));
    path(p[dest]);
}

int main()
{
    int A, u, v, w, ori, dest, mini;
    
    while(scanf("%d %d", &V, &A) && (V+A)) {
        grf.clear(), grf.resize(V);
        scanf("%d %d", &ori, &dest);
        while(A--) {
            scanf("%d %d %d", &u, &v, &w);
                grf[u].insert(ii(v,w));
        }

        mini = sssp(ori, dest);
	path(dest);

        while(dis[dest] == mini && dis[dest] != INF) {
            path(dest);
            sssp(ori, dest);
        }
        printf("%d\n", (dis[dest] == INF)? -1:dis[dest]);

    }
}
