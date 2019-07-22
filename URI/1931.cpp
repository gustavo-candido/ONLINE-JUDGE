#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> grf, grf2;
int V, A;


int main()
{
    int o, d, w;

    scanf("%d %d", &V, &A);

    grf.resize(A+1);
    grf2.resize(A+1);
    for(int i=1; i<=A; i++) {
        scanf("%d %d %d", &o, &d, &w);
        grf[o].push_back(ii(d, w));
        grf[d].push_back(ii(o, w));
    }

    for(int u=1; u<=V; u++) {
        for(int i=0; i<(int)grf[u].size(); i++) {
            int v = grf[u][i].F;
            if(grf[v].size() == 1) continue;
            for(int j=0; j<(int)grf[v].size(); j++) {
                int k = grf[v][j].F;
                if(k == u) continue;
                grf2[u].push_back(ii(k,  grf[u][i].S+grf[v][j].S));
            }
        }
    }
    grf.clear();

    deque<int> q;
    int dis[V+1];
    bitset<50005> iq;
    memset(dis, 0x3F3F3F3F, sizeof dis);
    dis[1] = 0;
    iq[1] = 1;
    q.push_back(1);

    while(q.size()) {
        int u = q.front();
        q.pop_front();
        iq[u] = 0;
        for(int i=0; i<(int)grf2[u].size(); i++) {
            int v = grf2[u][i].F;
                w = grf2[u][i].S;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                if(iq[v] == 0) {
                        if(q.size() && dis[v] < dis[q.front()])q.push_front(v);
                        else q.push_back(v);
                        iq[v] = 1;
                }
            }
        }
    }
    printf("%d\n", (dis[V] == 0x3F3F3F3F)? -1:dis[V]);
}
