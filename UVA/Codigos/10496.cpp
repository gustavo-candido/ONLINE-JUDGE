#include <bits/stdc++.h>
using namespace std;

int T, n, x[20], y[20], box[20][20], dp[20][1 << 20];

int tsp(int pos, int bit) {
	if(bit == (1<<(n+1))-1) return box[pos][0];
	if(dp[pos][bit] != -1) return dp[pos][bit];
	
	int ans = 200000000;
	
	for(int i=0; i<=n; i++) {
		if(i != pos && !(bit &(1<<i))) ans = min(ans, box[pos][i]+tsp(i, bit|(1<<i)));
	}
	return dp[pos][bit] = ans;
}

int main ()
{	
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			scanf("%d %d", &x[i], &y[i]);
		}
		for(int i=0; i<=n; i++)
			for(int j=0; j<=n; j++)
				box[i][j] =  abs(x[i] - x[j]) + abs(y[i] - y[j]);
		memset(dp, -1, sizeof(dp));
		printf("The shortest path has length %d\n", tsp(0,1));
	}
}
