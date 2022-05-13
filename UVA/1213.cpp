#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
	int x = (int)sqrt(n);
	for(int i=2; i<=x; i++) {
		if(n%i == 0) return false;
	}

	return true;
}

vector<int>coin;
int dp[200][1200][15];

int knap(int id, int n, int k) {
	if(n == 0 && k == 0) return 1;
	if(id >= coin.size() || n < 0 || k < 0) return 0;
	if(dp[id][n][k] != -1) return dp[id][n][k];
	
	return dp[id][n][k] = knap(id+1, n, k) + knap(id+1, n-coin[id], k-1);
}

int main()
{
	for(int i=2; i<=1120; i++) {
		if(prime(i))coin.push_back(i);
	}
	
	memset(dp, -1, sizeof dp);
	int n, k;
	while(scanf("%d %d", &n, &k) && n+k){
		
		printf("%d\n", knap(0, n, k));
	}
}
