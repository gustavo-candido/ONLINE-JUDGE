#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector< pair< int,pair<int,int> > > edge;
vector<int>set;

void inicia () {
	set.resize(m);
	for(int i=0; i<m; i++) {
		set[i]=i;
	}
}

int find_comp(int i) {
	if(set[i] == i) return i;
	else return set[i] = find_comp(set[i]);
}

bool mesma_comp (int i, int j) {
	if(find_comp(i) == find_comp(j)) return true;
	else return false;
}

void uni_comp(int i, int j) {
	set[find_comp(i)] = set[find_comp(j)];
}

int main()
{
	int ori, dest, w, mst, tot;
	while(scanf("%d %d", &m, &n)) {
		if(m == 0 && n == 0)break;
		inicia();
		tot = mst = 0;
		for(int i=0; i<n; i++){
			scanf("%d %d %d", &ori, &dest, &w);
			edge.push_back(make_pair(w, pair<int,int>(ori,dest)));
			tot+=w;
		}	
		sort(edge.begin(), edge.end());
		for(int i = 0; i<n; i++) {
			if(!mesma_comp(edge[i].second.first, edge[i].second.second)) {
				uni_comp(edge[i].second.first, edge[i].second.second);
				mst+=edge[i].first;
			}
		}
		printf("%d\n", tot-mst);
		edge.clear();
	}
}
