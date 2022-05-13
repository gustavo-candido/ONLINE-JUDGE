#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > box;
vector<int> vis, ord;
int V, A, ori, dest;

void dfs(int ini) {
	vis[ini] = 1;
	for(int i=0; i<box[ini].size(); i++) {
		if(vis[box[ini][i]] == -1) dfs(box[ini][i]);
	} 
	ord.push_back(ini);
}

void DFS(int ini) {
	for(int i=1; i<=V; i++) {
		if(vis[i] == -1) dfs(i);
	}
}

int main ()
{
	while(scanf("%d %d", &V, &A)) {
		if(V==0 && A==0) break;
		box.resize(V+1);
		ord.clear();
		for(int i=0; i<A;i++) {
			scanf("%d %d", &ori, &dest);
			box[ori].push_back(dest);
		}
		vis.assign(V+1, -1);
		DFS(1);
		for(int i=ord.size()-1; i>0; i--) {
			printf("%d ", ord[i]);
		}
		printf("%d\n", ord[0]);
	}
}
