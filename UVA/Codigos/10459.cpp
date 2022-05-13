#include <bits/stdc++.h>
#define INF 10000000
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;


vii box;
int N, D, s, t;
vi dist, wdist;
queue<int>q, worst;

int bfs(int ini) {
	int last;
	dist.assign(N+1, INF);
	dist[ini]=0;
	q.push(ini);
	while(q.size()) {
		int u = q.front(); q.pop();
		
		for(int i=0; i<(int)box[u].size(); i++) {
			int v = box[u][i];
			if(dist[v] == INF) {
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
		if(q.empty()) last = u;
		
	}
	for(int i=1; i<=N; i++) {
		if(wdist[i] < dist[i]) wdist[i] = dist[i];
	}
	return last;
}

int main()
{
	int n, ori, dest;
	while(scanf("%d", &N) != EOF) {
		box.resize(N+1);
		wdist.assign(N+1, -1);
		for(int i=0; i<N; i++) {
			scanf("%d", &n);
			for(int j=0; j<n; j++) {
				scanf("%d %d", &ori ,&dest);
				box[ori].push_back(dest);
				box[dest].push_back(ori);
			}
		}
		s = bfs(1);
		t = bfs(s);
		D = dist[s];
		printf("s = %d\nt = %d\nD = %d\n", s, t, D);
		//wdist = dist;
		for(int i=1; i<=N; i++) printf(" %d", dist[i]);puts("");
		for(int i=1; i<=N; i++) printf(" %d", wdist[i]);puts("");
		worst.push(t);
		while(worst.size()) {
			int u = worst.front();worst.pop();
			bfs(u);
			for(int i=1; i<=N; i++) 
			if(wdist[i] == D){
				worst.push(i);
			}
		}
		printf("Best Roots :");
		for(int i=1; i<=N; i++) {
			if(wdist[i] == ceil(D/2)) printf(" %d", i); 
		}
		printf("\nWorst Roots :");
		for(int i=1; i<=N; i++) {
			if(wdist[i] == D) printf(" %d", i); 
		}puts("");
		box.clear();
		wdist.clear();
	}
}
