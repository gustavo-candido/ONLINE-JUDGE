#include <bits/stdc++.h>
using namespace std;

int n, k, dp[101];

void go(int x, int i) {
	if(x <= 0 || x > n) return;

	dp[x] = true;

	go(x+2*i-1, i+1);
	go(x-2*i+1, i+1);
}

int main()
{
	while(scanf("%d %d", &n, &k) && (n+k)) {
		if(n>50) {
			puts("Let me try!");
			continue;
		}
		memset(dp, 0, sizeof dp);

		go(1, 2);

		if(dp[k]) puts("Let me try!");
		else puts("Don't make fun of me!");


	}
}