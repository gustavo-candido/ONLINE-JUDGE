#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector< vi > grf, tgrf;
vi vis;
stack<int> ts;

void kosaraju (int ini, int pass) {
	vis[ini] = 1;
	vi viz;
	if(pass == 1) viz = grf[ini];	
	else viz = tgrf[ini];

	for(int i=0; i<viz.size(); i++) 
		if(!vis[viz[i]]) 
			kosaraju (viz[i], pass);
	
	ts.push(ini);
}


int main()
{
	int V, A, u, v, p;

	while(cin >> V >> A && (V+A)) {
		grf.clear(); grf.resize(V+1);
		tgrf.clear(); tgrf.resize(V+1);
		while(A--) {
			cin >> u >> v >> p;

			grf[u].push_back(v);
			tgrf[v].push_back(u);
			if(p == 2) {
				grf[v].push_back(u);
				tgrf[u].push_back(v);
			}
		}
		vis.assign(V+1, 0);
	
		for(int i=1; i<=V; i++) 
			if(!vis[i]) kosaraju(i, 1);

		int scc=0;
		vis.assign(V+1, 0);
		while(ts.size()) {
			u = ts.top();ts.pop();
			if(!vis[u]) {
				scc++;
				kosaraju(u, 2);				
			}
		}
		cout << ((scc == 1)? 1:0) << endl;		
	} 
}