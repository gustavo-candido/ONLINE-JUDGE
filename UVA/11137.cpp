#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
ll coin[26], dp[10001][26];

ll cc(ll val, int id) {
	if(val < 0 || id >= 21) return 0;
	if(val == 0) return 1;
	if(dp[val][id] != -1) return dp[val][id];
	return dp[val][id] = cc(val-coin[id], id)+ cc(val, id+1);
}
int main()
{

	for(ll i=1; i<26; i++) coin[i-1] = i*i*i;

	ll n;

	while(scanf("%lld", &n) != EOF) {
		memset(dp, -1, sizeof dp);
		printf("%lld\n", cc(n, 0));
	}
	
}
