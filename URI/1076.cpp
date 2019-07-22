#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > box;
vector<int>vis, ts;
int V, E, cont;

void dfs(int ini){
	vis[ini] = 1;
	
	for(int i=0; i<(int)box[ini].size(); i++) {
		if(vis[box[ini][i]] == -1) {cont++;dfs(box[ini][i]);}
	}
}

void dfs_call(){
	vis.assign(V+1, -1);
	for(int i=0; i<=V; i++)
		if(vis[i] == -1) {
			dfs(i);
		}
}
int main()
{
	int s, t, st, d;
	
	cin >> t;
	while(t--) {
		cin >> st >> V >> E;
		box.resize(V);
		for(int i=0; i<E; i++) {
			cin >> s >> d;
			box[s].push_back(d);
			box[d].push_back(s);
		}
		cont=0;
		vis.assign(V, -1);
		
		dfs(st);
		cout << cont*2 << endl;
		box.clear();
	}
}
