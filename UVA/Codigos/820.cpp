#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector<int> >box, peso;

vector<int>dist, p;
int V, a, s, t, ori, dest, w, f, mf, C=1;

void augment(int v, int min_edge) {
	if(v == s) {
		f = min_edge;
		 return;
	}
	else if(p[v] != -1) {
		augment(p[v], min(min_edge, peso[p[v]][v]));
		peso[p[v]][v]-=f; 
		peso[v][p[v]]+=f;
	}
}

int max_flow() {
	mf=0;
	while(1) {
		f=0;
		dist.assign(V+1, INF);
		dist[s] = 0;
		p.assign(V+1, -1);
		queue<int> q;	
		q.push(s);
		while(q.size()) {
			int u = q.front();q.pop();
			
			if(u == t) break;
			
			for(int i=0; i<(int)box[u].size(); i++) {
				int v = box[u][i], d = peso[u][v];
				if(d > 0 && dist[v] == INF) {
					q.push(v);
					p[v] = u;
					dist[v] = dist[u]+1;
				}
			}
		}
		
		augment(t, INF);
		if(f == 0) break;
		mf+=f; 
	}
	
	return mf;
}

int main ()
{
	while(scanf("%d", &V) && V) {
		scanf("%d %d %d", &s, &t, &a);
		box.resize(V+1);
		peso.resize(V+1, vector<int>(V+1, 0));
		while(a--) {
			scanf("%d %d %d", &ori, &dest, &w);
			box[ori].push_back(dest);
			box[dest].push_back(ori);
			peso[ori][dest] += w;
			peso[dest][ori] += w;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", C,max_flow());
		box.clear();
		peso.clear();
		C++;
	}
}
	
