#include <bits/stdc++.h>
using namespace std;

int N, T, P, dp[80][80];
int F(int n, int t) {
	if(n == 0 && t == 0) return 1;
	if(t < 0 || n < 0) return 0;
	if(dp[n][t] != -1) return dp[n][t]; 
	int ans = 0;
	for(int i=P; i<=P+(T-P*N); i++) if(t-i >= 0)ans+=F(n-1, t-i);	
	return dp[n][t] = ans;
}

int main()
{
	int t;
	
	cin >> t;
	
	while(t--) {
		cin >> N >> T >> P;
		memset(dp, -1, sizeof dp);
		cout << F(N, T) << endl;
	}
}
