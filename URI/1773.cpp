#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

vector<int> grf[1003], sala[1003];
int n, m, keys[1003], in_queue[1003];
bool vis[1003];

bool search(){
	memset(vis, 0, sizeof vis);
	memset(in_queue, 0, sizeof in_queue);
	memset(keys, 0, sizeof keys);

	priority_queue<ii, vector<ii> > pq;


	pq.push({1,1});

	keys[1] = true;


	while(pq.size()) {
		int key = pq.top().first;
		int u = pq.top().second;

		pq.pop();

		in_queue[u] = 1;

		if(key ==  0 || vis[u]) continue;

		for(auto x: sala[u]){
			keys[ x ] = true;
			if(in_queue[x] && !vis[x]) pq.push({1, x});
		}


		for(auto v: grf[u]){
			if(vis[v]) continue;
			pq.push({keys[v], v});
			in_queue[v] = 1;
		}

		vis[u] = true;

	}

	for(int i=1; i<=n; i++) {
		if(!keys[i] || !in_queue[i]) return false;
	}

	return true;
}

int main()
{
	while(scanf("%d %d", &n, &m) != EOF) {

		for(int i=0; i<m; i++) {
			int o, d;

			scanf("%d %d", &o, &d);

			grf[o].push_back(d);
			grf[d].push_back(o);
		}

		for(int i=2; i<=n; i++) {
			int x;

			scanf("%d", &x);

			sala[x].push_back(i);
		}


		if(search()) puts("sim");
		else puts("nao");


		for(int i=1; i<=n; i++) {
			grf[i].clear();
			sala[i].clear();
		}
	}

}