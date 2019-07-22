// 2734 - Trocando Presentes

#include <bits/stdc++.h>
using namespace std;

const int N = 102;
const int MAX_SUM = 1003;

int n, v[2*N], sum;
bool dp[MAX_SUM][N];

int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {
		memset(dp, 0, sizeof dp);
		dp[0][0] = 1;
		sum = 0;

		scanf("%d", &n);

		for(int i=0; i<2*n; i++) {
			scanf("%d", &v[i]);
			sum+=v[i];
		}

		for(int i=0; i<2*n; i++) {
			for(int s=sum; s>=0; s--) {
				if(s-v[i] < 0) break;
				
				for(int k=1; k<=n; k++){
					dp[s][k]|=dp[s-v[i]][k-1];
				}
			}
		}


		int ans=100000008;

		for(int s=0; s<=sum; s++) {
			if(dp[s][n]) {
				ans = min(ans, abs(s - (sum-s)));
			}
		}

		printf("%d\n", ans);
	}
}