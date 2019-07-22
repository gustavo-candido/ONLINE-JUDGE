#include <bits/stdc++.h>
#define INF 100000000
#define _n 17
using namespace std;

double dp[1 << _n];
bool vis[1 << _n];
pair<double, double>vet[_n];
int n;

double dist(pair<double, double> a, pair<double, double> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

double go(int teans) {
    if(teans == (1 << n)-1) return 0;
    double &ans = dp[teans];
    if(vis[teans]) return ans;
    vis[teans] = 1;
    ans = INF;
    for(int i=0; i<n; i++) {
        if(teans & 1<<i) continue;
        teans|=(1<<i);
        for(int j=i+1; j<n; j++) {
            if(teans & 1<<j) continue;
            ans = min(ans, go(teans|(1<<j)) + dist(vet[i], vet[j]));
        }
        teans^=(1<<i);
    }
    return ans;
}

int main()
{
    int C;

    scanf("%d", &C);

    while(C--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++)
            scanf("%lf %lf", &vet[i].first, &vet[i].second);

        memset(vis, 0, sizeof vis);
        printf("%.2lf\n", go(0));
    }
}
