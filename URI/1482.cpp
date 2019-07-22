#include <bits/stdc++.h>
using namespace std;

int N,  museu[21], dis[21][21], maxi, t, ans, dp[1<<20];
bitset< 1<<20 >vis;

int tour(int last, int left, int bit) {
	if(left < 0) return -9999;
	if(left == 0) return 0;
	if(vis[bit]) return dp[bit];
        vis[bit] = 1;
        int p = 0, p1;
	for(int i=0; i<N; i++){
		if(bit & (1<<i)) continue;
		if(left-museu[i]-dis[last][i] >= 0){
                p1 = tour(i, left-museu[i]-dis[last][i], bit|(1<<i));
                p = max(p, p1+1);
		}
	}
	return dp[bit] = p;
}

int main()
{

	while(scanf("%d", &N) && N) {
		for(int i=0; i<N; i++)
			scanf("%d", &museu[i]);

		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				scanf("%d", &dis[i][j]);

		for(int k=0; k<N; k++)
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);


		ans = 0;

		for(int i=0; i<N; i++) {
            vis.reset();
			if(museu[i] <= 420){
				ans = max(ans, 1+tour(i, 420-museu[i], 1 <<i));
			}
		}
		cout << ans << endl;
	}
}
