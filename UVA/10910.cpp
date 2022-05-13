#include <bits/stdc++.h>
using namespace std;

int n, t, p, dp[73][73];

int f(int a, int b){
	if(a == n && b == t) return 1;
	if(a > n || b+(n-a)*p > t) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	int ans = 0;
	for(int x = p; x <= t - p * (n-1); x++) {
		ans+=f(a+1, b+x);
	}
	return dp[a][b] = ans;
}

int main() 
{
	int k;
	
	cin >> k;

	while(k--) {
		scanf("%d %d %d", &n, &t, &p);
		memset(dp, -1, sizeof dp);
		printf("%d\n", f(0, 0));
		
	}
}
