#include <bits/stdc++.h>
#define INF 200000000
using namespace std;

vector<vector<int> >box;
vector<int> color;
queue<int>f;
int V, A, X, x;


bool bfs(int u) {
	bool bipartide = true;
	color[u] = 0;
	X = 1;x=0;
	f.push(u);
	while(f.size()){
		int top = f.front();
		for(int i=0; i<box[top].size(); i++) {
			if(color[box[top][i]] == INF) {
				color[box[top][i]] = 1 - color[top];
				if(color[box[top][i]] == 1) x++;
				f.push(box[top][i]);
				X++;
			}
			else if(color[box[top][i]] == color[top]) {
				bipartide = false;
				break;
			}
		}
		f.pop();
	}
	return bipartide;
}

int BFS() {
	bool flag;
	int guards=0, z;
	for(int i=0; i<V; i++) {
		if(color[i]==INF) {
			flag = bfs(i);
			if(flag) {
				z = min(X-x, X-(X-x));
				if(z!=0)guards += z;
				else guards += z+1;
			}
			else {
				guards= -1;
				return guards;
			}
		}
	}
	return guards;
}

int main ()
{
	int ori, dest, T;
	
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &V, &A);
		box.resize(V);
		color.assign(V, INF);
		for(int i=0; i<A; i++) {
			scanf("%d %d", &ori, &dest);
			box[ori].push_back(dest);
			box[dest].push_back(ori);
		}
		printf("%d\n", BFS());
		box.clear();
	}
}
