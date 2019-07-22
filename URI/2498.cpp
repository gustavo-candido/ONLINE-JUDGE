#include <bits/stdc++.h>
using namespace std;


const int N = 1003;

int dp[N][101], n, c, cost[N], val[N], caso=0;


int main()
{
    while(scanf("%d %d", &n, &c) && n+c) {
        for(int i=1; i<=n; i++) scanf("%d %d", &cost[i], &val[i]);

        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=0; i<=c; i++) dp[0][i] = 0;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=c; j++) {
                dp[i][j] = dp[i-1][j];
                if(j-cost[i]>=0) dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i]]+val[i]);
            }
        }

        printf("Caso %d: %d\n", ++caso, dp[n][c]);
    }   
}   