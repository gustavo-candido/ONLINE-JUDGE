#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, v[100000], m, tot;
	char aux;
	scanf("%d", &n);
	getchar();
	while(n--) {
		m = tot = 0;
		while(scanf("%d%c", &v[m++], &aux) && aux == ' ')tot+=v[m-1];
		tot+=v[m-1];

		if(tot%2 != 0) {puts("NO");continue;}
		tot/=2;
		int dp[tot+1];
		memset(dp, 0x3F3F3F3F, sizeof dp);

		dp[0] = 1;

		for(int j=0; j<m; j++) {
			for(int i = tot; i>=0; i--) {
				if(i+v[j] <= tot) dp[i+v[j]] = min(dp[i+v[j]], dp[i]+1);
			}
		}

		printf("%s\n", (dp[tot] < 0x3F3F3F3F)?"YES":"NO");
	}
}

