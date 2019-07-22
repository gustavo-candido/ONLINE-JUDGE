#include <bits/stdc++.h>
#define inf 0X3F3F3F3F
using namespace std;

int main()
{
	int fat[11], n, dp[100005];

	fat[0] = 1;
	for(int i=1; i<11; i++) 
		fat[i] = fat[i-1]*i;

	scanf("%d", &n);
	memset(dp, inf, sizeof dp);

	dp[0] = 0;

	for(int i=1; i<=n; i++) {
		for(int j=0; j<11; j++) {
			if(i-fat[j] >= 0) dp[i] = min(dp[i], dp[i-fat[j]]+1);
		}
	}
	printf("%d\n", dp[n]);
}