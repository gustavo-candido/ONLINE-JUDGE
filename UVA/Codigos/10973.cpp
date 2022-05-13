#include <bits/stdc++.h>
using namespace std;

int t, V, A, o, d;

typedef unsigned long long int ull;

int main()
{
	
	scanf("%d", &t);

	while(t--) {
		set<ull> ans;
		
		scanf("%d %d", &V, &A);
		bool adj[V+1][V+1];
		memset(adj, 0, sizeof(adj));
		for(int i=0; i<A; i++) {
			scanf("%d %d", &o, &d);o--, d--;
			adj[o][d] = 1;
			adj[d][o] = 1;
		}
		for(int u=0; u<V; u++) {
			for(int v=u+1; v<V; v++) {
				if(!adj[u][v])continue;
				for(int k=v+1; k<V; k++) {
					if(!adj[v][k]) continue;
					if(adj[u][v] && adj[v][k] && adj[k][u]) {
						int a = min(min(u,v),k);
						int b = max(max(u,v),k);
						int c;
						if(u != k && u != v)  c = u;
						if(v != k && v != k)  c = v;
						if(k != u && k != v)  c = k;
						ull n = 3*2007*a + 2*2007*2007*b + 2007*2007*2007*c;
						ans.insert(n);
					}
				}
			}
		}
		printf("%lld\n", ans.size());
	}
}
