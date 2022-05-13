#include <bits/stdc++.h>
#define F first
#define S second
#define INF 100000000
using namespace std;

typedef pair<int,int>ii;
typedef vector<int> vi;

vector<vi>grf;
int vis[50010];
int V;
bitset<50010> iq;
int dfs(int u, int &n) {
	iq[u] = 1;
	vis[u] = 1;
	int v;
	for(int i=0; i<grf[u].size(); i++) {
		v = grf[u][i];
		if(vis[v] == 0) dfs(v, n+=1);
	}
	return n;
}

int dfs_call() {
	int mini = INF, maxi = -INF;
	int aux;
	iq.reset();
	for(int i=0; i<V; i++) {
		if(iq[i] == 0) {
			memset(vis, 0, sizeof(int)*V);
			aux = 1;
			dfs(i, aux);
			if(aux > maxi) {mini = i; maxi = aux;}
		}
	}
	return mini+1;
}

int main()
{
	int T, o, d;

	scanf("%d", &T);
	
	for(int C=1; C<=T; C++) {
		scanf("%d", &V);
		grf.clear();
		grf.resize(V);
		for(int i=0; i<V; i++) {
			scanf("%d %d", &o, &d); o--, d--;
			grf[o].push_back(d);
		}
		printf("Case %d: %d\n", C, dfs_call());
	}
} 
