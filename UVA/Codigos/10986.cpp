#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

int V, A, ori, dest, s, t, w;
map < int, vector< pair<int,int> > >box;
vector<int>dist;
priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > >pq;
int main ()
{
	int n;
	
	scanf("%d", &n);
	
	for(int c=1; c<=n; c++) {
		scanf("%d %d %d %d", &V, &A, &s, &t);
		for(int i=0; i<A; i++) {
			scanf("%d %d %d", &ori, &dest, &w);
			box[ori].push_back(make_pair(dest, w));
			box[dest].push_back(make_pair(ori, w));
		}
		dist.assign(60000,INF);
		dist[s]=0;
		pq.push(make_pair(0,s));
		while(!pq.empty()) {
			pair<int, int> front = pq.top();pq.pop();
			int d = front.first, u = front.second;
			if(d > dist[u]) continue;
			for(int i=0; i<(int)box[u].size(); i++) {
				int v = box[u][i].first;
				int custo = box[u][i].second;
				if(dist[u] + custo < dist[v]){
					dist[v] = dist[u]+custo;
					pq.push(make_pair(dist[v], v));
				}
			}
		}
		if(dist[t]!=INF)printf("Case #%d: %d\n", c, dist[t]);
		else printf("Case #%d: unreachable\n", c);
		box.clear();
	}
}
