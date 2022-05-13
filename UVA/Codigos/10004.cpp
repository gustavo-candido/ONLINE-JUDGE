#include <bits/stdc++.h>
#define INF 2000000000
using namespace std;

vector<vector<int> >box;
vector<int> color;
queue<int>f;
int V, A;

bool bfs() {
	bool bipartide = true;
	f.push(0);
	color[0] = 0;
	while(f.size()) {
		int topo = f.front();
		for(int i=0; i<box[topo].size(); i++) {
			if(color[box[topo][i]] == INF) {
				color[box[topo][i]] = 1 - color[topo];
				f.push(box[topo][i]);
			}
			else if (color[box[topo][i]] == color[topo]) {
				bipartide = false;
				break;
			}
		}
		f.pop();
	}
	return bipartide;
}

int main ()
{
	int ori, dest;
	bool ans;
	while(scanf("%d", &V) && V) {
		box.resize(V);
		color.assign(V, INF);
		scanf("%d", &A);
		
		for(int i=0; i<A; i++) {
			scanf("%d %d", &ori, &dest);
			box[ori].push_back(dest);
			box[dest].push_back(ori);
		}
		ans = bfs();
		if(ans) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
		box.clear();
	}
}
