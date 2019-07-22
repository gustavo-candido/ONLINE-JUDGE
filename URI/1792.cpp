#include <bits/stdc++.h>
using namespace std;

struct state{
	int id, enemies, degree;

	state(){
		id = enemies = degree = 0;
	}

	state(int _id, int _enemies, int _degree) {
		id = _id;
		enemies = _enemies;
		degree = _degree;
	}

	bool operator > (state other) const{
		if(degree != other.degree) return !(degree < other.degree);
		if(enemies != other.enemies) return !(enemies < other.enemies);
		return !(id < other.id);  
	}
};


int n, m, s, enemies[10004], alies[10004], min_degree[10004], vis[10004];
vector<int> grf[10004];


bool check(){
	priority_queue<state, vector<state>, greater<state> > pq;


	for(int i=1; i<=n; i++) {
		if(min_degree[i] == 0) {
			pq.push(state(i, enemies[i], 0));
		}
	}

	while(pq.size()) {
		state topo = pq.top(); pq.pop();
		if(s <= topo.enemies) break;

		if(topo.degree != 0 || vis[topo.id]) continue;

		s+=alies[topo.id];

		for(auto v: grf[topo.id]) {
			if(vis[v]) continue;
			min_degree[v]--;
			pq.push(state(v, enemies[v], min_degree[v]));
		}

		vis[topo.id] = true;
	}

	for(int i=1; i<=n; i++) {
		if(!vis[i]) return false;
	}
	return true;
}

int main()
{
	while(scanf("%d %d %d", &n, &m, &s) && (n+m+s)) {

		for(int i=1; i<=n; i++) scanf("%d", &enemies[i]);
		for(int i=1; i<=n; i++) scanf("%d", &alies[i]);

		memset(min_degree, 0, sizeof min_degree);
		memset(vis, 0, sizeof vis);

		for(int i=0; i<m; i++) {
			int o, d;

			scanf("%d %d", &o, &d);

			grf[o].push_back(d);

			min_degree[d]++;
		}

		if(!check()) printf("im");
		puts("possivel");


		for(int i=0; i<=n; i++) {
			grf[i].clear();
		}

	}
}