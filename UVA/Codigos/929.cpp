#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector< pair<int,int> > >box;
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > >pq;
vector< vector<int> >m;
vector<int>dist;
int T, r, c;

int dijkstra(int ori, int dest) {
	dist.assign(r*c,INF);
	
	dist[ori]=m[0][0];
	pq.push(make_pair(m[0][0],ori));
	while(!pq.empty()) {
		pair<int,int> front = pq.top();pq.pop();
		int d = front.first, u = front.second;
			if(d > dist[u]) continue;
		for(int i=0; i<(int)box[u].size(); i++) {
			int v = box[u][i].first, w = box[u][i].second;
			if(dist[u]+w < dist[v]) {
				dist[v] = dist[u]+w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
	dist.clear();
	return dist[r*c-1];
}

int main ()
{
	
	scanf("%d", &T);
	
	while(T--) {
		scanf("%d %d", &r, &c);
		
		m.resize(r);
		for(int i=0; i<r; i++) {
			m[i].resize(c);
			for(int j=0; j<c; j++) {
				scanf("%d", &m[i][j]);
			}
		}
		int x=0;
		box.resize(r*c);
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				if(i!=0)box[x].push_back(make_pair(x-c,m[i-1][j]));
				if(j!=0)box[x].push_back(make_pair(x-1,m[i][j-1]));
				if(j!=c-1)box[x].push_back(make_pair(x+1,m[i][j+1]));
				if(i!=r-1)box[x].push_back(make_pair(x+c,m[i+1][j]));
				x++;
			}
		}
		printf("%d\n", dijkstra(0, r*c-1));
		box.clear();
		m.clear();
	}
}
