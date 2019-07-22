#include <bits/stdc++.h>
#define F first
#define S second
#define _n 505
using namespace std;

typedef pair<double, double> dd;
typedef pair<double, dd> ddd;

double x[_n], y[_n];
ddd peso[_n*_n];
int V, p[_n];

int acha(int u) {
    return p[u] = (p[u] == u)? u:acha(p[u]);
}
bool same(int u, int v) {
    return acha(u) == acha(v);
}

void uni(int u, int v) {
    p[acha(v)] = p[acha(u)];
}

int main()
{
    int t;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &V);
        for(int i=0; i<V; i++) {
            scanf("%lf %lf", &x[i], &y[i]);
        }
        int z=0;
        for(int i=0; i<V; i++) {
            for(int j=i+1; j<V; j++) {
                peso[z] = ddd(hypot(x[i] - x[j], y[i] - y[j]), dd(i, j));
                z++;
            }
        }
        stable_sort(peso, peso+z);

        for(int i=0; i<V; i++) p[i] = i;

        double ans = 0;
        for(int i=0; i<z; i++) {
            if(!same(peso[i].S.F, peso[i].S.S)){
                    uni(peso[i].S.F, peso[i].S.S);
                    ans+=peso[i].F;
            }
        }
        printf("%.2lf\n", ans/100.0);
    }
}
