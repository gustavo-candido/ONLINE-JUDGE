#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> grf;
int V, p[300], vis[300];
bool cut;

void solution(int u) {
		vi ans;
		ans.push_back(0);
		do {
			ans.push_back(u);
		u = p[u];
	}while(u != -1);
	
	bool f= false;
	for(int i=ans.size()-1; i>=0; i--){
		if(f) printf(" ");
		printf("%d", ans[i]+1);
		f = 1;
	}
	puts("");
	cut = 1;
}
void dfs(int u, int s) {
	if(s == V) {
		for(int i=0; i<(int)grf[u].size(); i++) {
			int v = grf[u][i];
			if(v == 0) {solution(u);return;}
		}
		return;
	}
	for(int i=0; i<(int)grf[u].size(); i++) {
		if(cut) return;
		int v = grf[u][i];
		if(vis[v] == 0) {
			p[v] = u;	
			vis[v] = 1;
			dfs(v,s+1);
			p[v] = -1;
			vis[v] = 0;
			
		} 
	}
}
int main()
{
	int o, d;
	char line[80];
	while(scanf("%d", &V) != EOF) {
		getchar();
		grf.clear();
		grf.resize(V);
		while(gets(line) && strcmp(line, "%") != 0) {
			sscanf(line, "%d %d", &o, &d);o--, d--;
			grf[o].push_back(d);
			grf[d].push_back(o);
		}
		memset(p, -1, sizeof(int) * V);
		memset(vis, 0, sizeof(int) * V);
		vis[0] = 1;
		cut = 0;
		dfs(0,1);
		if(!cut) puts("N");
	}
}
