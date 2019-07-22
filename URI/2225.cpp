#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int N, M, K, grf[20][20], dp[1<<16][16][6];

inline int tsp(int id, int s, int k) {
    if(k < 0) return INF;

    if(s == (1<<N)-1) return 0;
    int &mem = dp[s][id][k];

    if(~mem) return mem;

    int ans=INF;

    for(int i=0; i<N; i++) {
        if(s & (1<<i) || id == i) continue;
        ans = min(ans, min(tsp(i, s|(1<<i), k)+grf[id][i], min(ans, tsp(i, s|(1<<i), k-1))));
    }
    return mem = ans;
}


int main()
{
    int t;

    scanf("%d", &t);

    while(t--) {
        memset(dp, -1, sizeof dp);
        scanf("%d %d %d", &N, &M, &K);
        memset(grf, INF, sizeof grf);
        for(int i=0; i<N; i++) grf[i][i]=0;
        while(M--) {
            int o, d, w;
            scanf("%d %d %d", &o, &d, &w);o--; d--;
            grf[o][d] = grf[d][o] = min(w, grf[o][d]);
        }
        for(int k=0; k<N; k++) {
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    grf[i][j] = min(grf[i][j], grf[i][k]+grf[k][j]);
                }
            }
        }
        int ans = tsp(0, (1<<0), K);
        if(ans >= INF) ans = -1;
        printf("%d\n", ans);

    }
}
