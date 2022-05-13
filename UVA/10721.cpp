#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[55][55][55];
int n, k, m;

ll f(int a, int b, int c) {	
	if(a > n || b > k || c > m) return 0LL;
	if(a == n && b == k && c <= m) return 1LL;
	if(dp[a][b][c] != -1) return dp[a][b][c];
	
	return dp[a][b][c] = f(a+1, b, c+1) + f(a+1, b+1, 1); 	
}

int main()
{
	while(scanf("%d %d %d", &n , &k, &m) != EOF) {
		memset(dp, -1, sizeof dp);
		printf("%lld\n", f(1, 1, 1));
	}
}
