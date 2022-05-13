#include <bits/stdc++.h>
#define ff first
#define ss second.first
#define tt second.second
using namespace std;

typedef pair<double, ii> iii;
typedef pair<int,int> ii;

int n, r, p[1005], state;
double road, rail;
vector<iii> adj;
ii v[1005];

double dist(double x, double y, double a, double b) {
    return hypot(x-a, y-b);
}

int find(int i) {
    return p[i] = ((p[i] == i)?i:find(p[i]));
}

bool same(int i, int j) {
    return (find(i) == find(j));
}

void uni(int i, int j) {
    if(same(i,j)) return;
    p[find(i)] = p[find(j)];
}

int main()
{
    int t;

    scanf("%d", &t);
    for(int Z=1; Z<=t; Z++) {
        adj.clear();
        scanf("%d %d", &n, &r);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &v[i].first, &v[i].second);
        }

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                double aux = dist(v[i].first, v[i].second, v[j].first, v[j].second);
                adj.push_back(iii(aux, ii(i, j)));
            }
        }
        sort(adj.begin(), adj.end());
        for(int i=0; i<n; i++) p[i] = i;

        state =  1;
        road = rail = 0.0;

        for(int i=0; i<adj.size(); i++) {
            if(!same(adj[i].ss, adj[i].tt)) {
                uni(adj[i].ss, adj[i].tt);
                if(adj[i].ff <= (double) r) {
                    road+=adj[i].ff;
                }
                else {
                    rail+=adj[i].ff;
                    state++;
                }

            }
        }

        printf("Case #%d: %d %.0lf %.0lf\n", Z, state, road, rail);
    }
}
