#include <bits/stdc++.h>
using namespace std;


int n, val[1002], w[1002], g, x[102], ans, dp[1002][1002], maxi;
int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);

		
		for(int i=1; i<=n; i++) {
			scanf("%d %d", &val[i], &w[i]);
		}
		
		
		scanf("%d", &g);

		maxi = 0;
		for(int i=0; i<g; i++){
			scanf("%d", &x[i]);
			maxi = max(maxi, x[i]);
		}
		
	
		for(int i=0; i<=n; i++) dp[0][i] = 0;
		for(int i=0; i<= maxi; i++)dp[i][0] = 0;

		for(int i=1; i<=n; i++) {
			for(int j=0; j<=maxi; j++) {
				dp[i][j] = dp[i-1][j];
				if(j >= w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+val[i]);
			}		
		}

		ans = 0;
		for(int i=0; i<g; i++){
			ans+=dp[n][x[i]];
		}
		
		printf("%d\n", ans);
	}
}
