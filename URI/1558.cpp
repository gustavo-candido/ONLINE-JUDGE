#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, dp[10005];
	memset(dp, 0, sizeof dp);
	for(int i=0; i<=10000; i++) {
		for(int j=0; j<=10000; j++){
			if(j*j + i*i >= 0 && j*j + i*i <= 10000)dp[j*j + i*i] = 1;
		}
	}
	while(scanf("%d", &n)!=EOF) {
		if(n < 0) puts("NO");
		else printf("%s\n", (dp[n] == 1)?"YES":"NO");
	}
}