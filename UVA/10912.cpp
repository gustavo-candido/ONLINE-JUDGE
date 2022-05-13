#include <bits/stdc++.h>
using namespace std;

int dp[27][27][450], l, s;


int f(int id, int k, int sum) {
	if(l == k && sum == s) return 1;
	if(k > l || sum > s || id > 26) return 0;
	if(dp[id][k][sum] != -1) return dp[id][k][sum];
	return  dp[id][k][sum] = f(id+1, k, sum) + f(id+1, k+1, sum+id);
}
int main()
{
	int C = 1;
	while(scanf("%d %d", &l, &s) && l+s) {
		memset(dp, -1, sizeof dp);
		printf("Case %d: ", C++);
		if(l > 26 || s> 450)printf("0\n");
		else printf("%d\n", f(1, 0, 0));
	}
}
