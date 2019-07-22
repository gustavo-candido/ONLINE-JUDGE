#include <bits/stdc++.h>
#define MAX 100050
#define F first
#define S second
#define INF 100000000
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int V, W, M = 20, lca[MAX][20], h[MAX], power[MAX][20];
int point[6000], val[6000], dp[6000][6000];
vector<vii> grf;

int max(int a, int b, int c) {
	return max(a, max(b, c));
}

void dfs(int u, int ult, int w) {
	  lca[u][0] = ult;
	power[u][0] = w;

	for(int i=1; i<M; i++) {
		  lca[u][i] = lca[lca[u][i-1]][i-1];
		power[u][i] = max(power[u][i-1], power[lca[u][i-1]][i-1]);
	}
	int v, d;

	for(int i=0; i<(int)grf[u].size(); i++) {
		v = grf[u][i].F, d = grf[u][i].S;

		if(v == ult) continue;

		h[v] = h[u] + 1;
		dfs(v, u, d);
		
	}
	return;
} 

ii get_lca(int a, int b) {
	if(h[a] < h[b]) swap(a,b);

	int d = h[a] - h[b];
	int maxi = power[a][0];

	for(int i = M-1; i >= 0; i--) {
		if(d & (1 << i)) {
			maxi = max(maxi, power[a][i]);
			a = lca[a][i];
		}
	}

	if(a == b) return ii(a, maxi);

	for(int i = M-1; i >= 0; i--) {
		if(lca[a][i] != lca[b][i]) {
			maxi = max(maxi, power[a][i], power[b][i]);
			a = lca[a][i];
			b = lca[b][i];
		}
	}

	maxi = max(maxi, power[a][0], power[b][0]);
	return ii(lca[a][0], maxi);
}

ii get_ans (int a, int b) {
	ii aux = get_lca(a, b);
	ii ans = ii(1 + h[a] + h[b] - 2 * h[aux.F], aux.S);
	return ans;
}

	
int knap(int id, int w) {
	if(id < 0 || !w) return 0;
	if(dp[id][w] != -1) return dp[id][w];
	if(point[id] > w) return dp[id][w] = knap(id-1, w);
	return dp[id][w] = max(knap(id-1, w), knap(id-1, w-point[id])+val[id]);
}

int main()
{
	int o, d, p, k;
	scanf("%d %d", &V, &W);

	grf.resize(V);

	for(int i=1; i<V; i++) {
		scanf("%d %d %d", &o, &d, &p); o--, d--;
		grf[o].push_back(ii(d,p));
		grf[d].push_back(ii(o,p));
	}
	h[0] = 0;
	dfs(0, 0, 0);

	scanf("%d", &k);
	
	ii aux;
	for(int i=1; i<=k; i++) {
		scanf("%d %d", &o, &d); o--, d--;
		aux = get_ans(o, d);
		point[i] = aux.F;
	       	  val[i] = aux.S;
	}
	memset(dp, -1, sizeof dp);
	int x = knap(k, W);
	if(!x) x = -1;
	printf("%d\n", x);
}