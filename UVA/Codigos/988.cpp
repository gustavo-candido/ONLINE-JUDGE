#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector<int> > box;
vector<int>ways, top, vis;
int V, n,dest, ans;

void dfs(int u) {
	vis[u]=1;
	for(int i=0;i<(int)box[u].size(); i++) {
		int v = box[u][i];
		if(!vis[v]) dfs(v);
	}
	top.push_back(u);
}

int main() {
	int C=0;
	while(scanf("%d", &V) != EOF) {
		box.resize(V+1);
		ways.assign(V+1, 0);
		vis.assign(V+1,0);
		for(int i=0; i<V; i++) {
			scanf("%d", &n);
			if(!n)box[i].push_back(V);
			while(n--) {
				scanf("%d", &dest);
				box[i].push_back(dest);
			}
		}
		dfs(0);
		ways[0]=1;
		for(int i = top.size()-1; i>=0; i--) {
			int u = top[i];
			for(int j=0; j<(int)box[u].size(); j++) {
				ways[box[u][j]]+=ways[u];
			}
			if(!box[u].size()) ans+=ways[u];
		}
		if(C) puts("");
		printf("%d\n", ways[V]);
		C=1;
		box.clear();
		ways.clear();
		top.clear();
		vis.clear();
	}
}
