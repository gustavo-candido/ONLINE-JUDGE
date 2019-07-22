#include <bits/stdc++.h>
using namespace std;

const int N = 10005;

int n, v[N], tree[4*N];

void build(int node, int l, int r) {
	if(l == r){
		tree[node] = l;
		return;
	}
	int m = (l+r)/2;
	
	build(2*node, l, m);
	build(2*node+1, m+1, r);

	if(v[tree[2*node]] < v[tree[2*node+1]])
		tree[node] = tree[2*node];
	else
		tree[node] = tree[2*node+1];
}


void upp(int node, int l, int r, int x) {
		if(l == x && r == x) {
			tree[node] = x;
			return;
		}

		if(l>=r)
			return;

		if(r < x || l > x)
			return;

		int m = (l+r)/2;

		upp(2*node, l, m, x);
		upp(2*node+1, m+1, r, x);

		if(v[tree[2*node]] < v[tree[2*node+1]])
			tree[node] = tree[2*node];
		else
			tree[node] = tree[2*node+1];
}


int min_range(int node, int l, int r, int a, int b) {
	if(a<=l && r<=b){
		return tree[node];
	} 

	if(l>r)
		return -1;

	if(r<a || l>b)
		return -1;

	int m = (l+r)/2;

	int p1 = min_range(2*node, l, m, a, b);
	int p2 = min_range(2*node+1, m+1, r, a, b);

	if(p1 == -1 && p2 == -1) return -1;
	if(p1 != -1 && p2 == -1) return p1;
	if(p1 == -1 && p2 != -1) return p2;

	if(v[p1] < v[p2]) return p1;
	return p2;

}


int main()
{
	int t;

	scanf("%d", &t);

	while(t--) {

		scanf("%d", &n);

		for(int i=1; i<=n; i++) {
			scanf("%d", &v[i]);
		}

		build(1, 1, n);

		int ans=0, ind;

		for(int i=1; i<=n; i++) {
			ind = min_range(1, 1, n, i, n);
			if(ind != i) ans++;

			swap(v[i], v[ind]);
			upp(1, 1, n, i);
			upp(1, 1, n, ind);
			
		}
		printf("%d\n", ans);
	}
}