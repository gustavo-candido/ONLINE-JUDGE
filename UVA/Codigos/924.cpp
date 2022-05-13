#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

int V, A, T,daily, first;
vector< vector<int> >box;
vector<int> dist, x;
queue<int>q;


int main ()
{
	scanf("%d", &V);
	box.resize(V);

	for(int i=0; i<V; i++) {
		scanf("%d", &A);
		box[i].resize(A);
		for(int j=0; j<A; j++) {
			scanf("%d", &box[i][j]);
		}
	}
	scanf("%d", &T);
	while(T--){
		x.assign(V, 0);
		daily = first = 0;
		dist.assign(V,INF);
		scanf("%d", &A);
		dist[A]=0;
		q.push(A);
		while(!q.empty()) {
			int u = q.front();q.pop();
			for(int i=0; i<(int)box[u].size(); i++) {
				if(dist[box[u][i]]==INF) {
					dist[box[u][i]] = dist[u]+1;
					x[dist[u]+1]++;
					q.push(box[u][i]);
				}
			}
		}
		for(int i=0; i<V; i++) {
			if(x[i] > daily) {
				daily = x[i];
				first = i;
			}
		}
		printf("%d", daily);
		if(daily) printf(" %d", first);
		puts("");
	}
}
