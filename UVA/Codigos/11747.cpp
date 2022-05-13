#include <bits/stdc++.h>
#define F first
#define S second.first
#define T second.second
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

vector<iii> grf;
vector<int> p;
bool ans;
int find(int x) {
	return p[x] = (p[x] == x)? x:find(p[x]); 
}

bool same (int i, int j) {
	return p[find(i)] == p[find(j)];
}

void uni(int i, int j) {
	p[find(i)] = p[find(j)];
}

int main()
{
	int V, A, o, d, w;
	while(scanf("%d %d", &V, &A) && V+A) {
		grf.clear();
		p.resize(V);
		ans = false;
		for(int i=0; i<V; i++) p[i] = i;
		for(int i=0; i<A; i++) {
			scanf("%d %d %d", &o, &d, &w);
			grf.push_back(iii(w, ii(o,d)));
		}
		sort(grf.begin(), grf.end());

		for(int i=0; i<A; i++) {
			if(!same(grf[i].S, grf[i].T)) uni(grf[i].S, grf[i].T);
			else {
				if(ans) printf(" ");
				printf("%d",grf[i].F);
				ans = true;
			}
		}
		if(!ans) printf("forest");
		puts("");
	}
}
