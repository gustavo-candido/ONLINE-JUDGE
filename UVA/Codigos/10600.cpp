#include <bits/stdc++.h>
#define F first
#define S second.first
#define T second.second
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
int V, A, mini, mini2;
vector<iii> grf;
vector<int>p;

int find(int x) {return p[x] = (p[x] == x)? x:find(p[x]); }
	
bool same(int i, int j) {
	return p[find(i)] == p[find(j)];
}

void uni(int i, int j) {
	p[find(i)] = p[find(j)];	
}

int main()
{
	int Z, o, d, w, mini, mini2;
	vector<int>used;
	scanf("%d", &Z);

	while(Z--) {
		grf.clear();
		used.clear();
		scanf("%d %d", &V, &A);
		p.resize(V);
		for(int i=0; i<V; i++) p[i] = i;

		for(int i=0; i<A; i++) {
			scanf("%d %d %d", &o, &d, &w); o--, d--;
			grf.push_back(iii(w, ii(o,d)));
		}
		sort(grf.begin(), grf.end());
		mini = 0;
		for(int i=0; i<A; i++) {
			if(!same(grf[i].S, grf[i].T)) {
				mini+=grf[i].F;
				uni(grf[i].S, grf[i].T);
				used.push_back(i);
			}
		}
		mini2 = 1e9;
		int count;
		int aux;
		for(int i=0; i<used.size(); i++) {
			for(int j=0; j<V; j++) p[j] = j;
			aux = count = 0;
			for(int j=0; j<A; j++) {
				if(used[i] == j) continue;
				if(!same(grf[j].S, grf[j].T)) {
					aux+=grf[j].F;
					uni(grf[j].S, grf[j].T);
					count++;
				}
			}
			if(count == V-1)mini2 = min(mini2, aux);
		}
		printf("%d %d\n", mini, mini2);
	}
}
