#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > grf;
int V, A;
char x;


int main(){
        int o, d;
        while(scanf("%d", &V) && V) {
            grf.clear();
            grf.resize(V+1);
            for(int i=1; i<=V; i++) {
                scanf("%d", &o);
                while(1) {
                    scanf("%d%c", &d, &x);
                    grf[o].push_back(d);
                    if(x != ' ') break;
                }
            }
            int dis[V+1];
            queue<int>q;
            bool f = true;
            memset(dis, 0x3F3F3F3F, sizeof dis);

            dis[1]  = 0;

            q.push(1);

            while(q.size()) {
                int u = q.front();
                q.pop();
                if(!f) continue;

                for(int i=0; i<(int)grf[u].size(); i++) {
                    int v  = grf[u][i];

                    if(dis[v] == dis[u]) {
                        f = false;
                        break;
                    }
                    if(dis[v] == 0x3F3F3F3F) {
                        dis[v] = 1 - dis[u];
                        q.push(v);
                    }
                }
            }
            printf("%s\n", (f)?"SIM":"NAO");
        }
}
