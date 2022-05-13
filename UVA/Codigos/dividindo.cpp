#include <bits/stdc++.h>
#define INF 100000000
using namespace std;

vector< vector<int> >box;
vector<int> dist;
queue<int>q;
int ori, dest, V, A;
bool x= true;

bool bipartide () {
	dist[0] = 0;
	q.push(0);
	x = true;
	while(q.size()) {
		int u = q.front();q.pop();
		for(int i=0; i<(int)box[u].size(); i++) {
			int v = box[u][i];
			if(dist[v] == INF) {
				dist[v] = 1 - dist[u];
				q.push(v);
			}
			else if(dist[u]==dist[v]) {x=false;break;}
		}
	}
	return x;
}

int main ()
{
	scanf("%d %d", &V, &A);
	
	box.resize(V);
	
	for(int i=0; i<A; i++) {
		scanf("%d %d", &ori, &dest);
		box[ori].push_back(dest);
		box[dest].push_back(ori);
	}
	dist.assign(V,INF);
	bipartide();
	
	if(x) printf("SIM\n");
	else printf("NAO\n");
	box.clear();
}
