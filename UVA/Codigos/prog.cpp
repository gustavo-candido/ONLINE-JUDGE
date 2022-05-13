#include <bits/stdc++.h>
#define INF 200000000
using namespace std;

typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
typedef vector<int> vi;

vector<vii> box;
vi dist;
int V;
int dijistra (int ori, int dest) {
	dist.assign(V, 	INF);
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(make_pair(ori, 0));
	
	while(pq.size()) {
		ii top = pq.top();pq.pop();
		int u = top.first, d = top.second;
		if(d > dist[u]) continue;
		for(int i=0; i<(int)box[u].size(); i++) {
			int v = box[u][i].first, w =  box[u][i].second; 
			if(dist[v] > dist[u]+w){
			   dist[v] = dist[u]+w;
			   pq.push(make_pair(v, dist[v]));
			}
		}
	}
	dist.clear();
	return dist[dest];
}

int main()
{
	
}
