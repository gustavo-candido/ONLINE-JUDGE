//USING ARRAY SEG_TREE
//O(N*log(N))
#include<bits/stdc++.h>
#define INF 1e9
#define _n 505
#define left(x) (x<<1)
#define right(x) (x<<1)+1
#define mid(x, y) (x+y)>>1
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;

ii tree[_n][4*_n];
int v[_n];

void build(int x, int node, int l, int r) {
	if(l == r) {
		tree[x][node].F = tree[x][node].S = v[l];
		return;
	}
	int L = left(node), R = right(node), M = mid(l, r);
	
	build(x, L, l  , M);
	build(x, R, M+1, r);
	tree[x][node].F = min(tree[x][L].F, tree[x][R].F);
	tree[x][node].S = max(tree[x][L].S, tree[x][R].S);
}

void upp(int x, int node, int l, int r, int a, int val) {
	if(l > a || r < a) return;
	if(l == a && r == a) {
		tree[x][node].F = tree[x][node].S = val;
		return;
	}
	int L = left(node), R = right(node), M = mid(l, r);
	upp(x, L, l  , M, a, val);
	upp(x, R, M+1, r, a, val);
	tree[x][node].F = min(tree[x][L].F, tree[x][R].F);
	tree[x][node].S = max(tree[x][L].S, tree[x][R].S);
} 

ii sum(int x, int node, int l, int r, int a, int b) {
	if(l > b || r < a) return ii(INF,-INF);
	if(l >= a && r <= b) return tree[x][node];
	int L = left(node), R = right(node), M = mid(l, r);
	
	ii p1 = sum(x, L, l  , M, a, b);
	ii p2 = sum(x, R, M+1, r, a, b);
	return ii(min(p1.F, p2.F), max(p1.S, p2.S));
}

int main()
{
	int n;

	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &v[j]);
		}
		build(i, 1, 1, n);
	}
	int q, x, y, a, b;
	ii aux, ans;
	char op;
	scanf("%d", &q);
	getchar();
	while(q--) {
		scanf("%c", &op);

		if(op == 'q') {
			scanf("%d %d %d %d", &x, &y, &a, &b);
			getchar();
			ans = ii(INF, -INF);
			for(int i=x; i<=a; i++) {
				aux = sum(i, 1, 1, n, y, b);
				ans = ii(min(ans.F, aux.F), max(ans.S, aux.S));
			}
			printf("%d %d\n", ans.S, ans.F);
		}

		else {
			scanf("%d %d %d", &x, &y, &a);
			getchar();
			upp(x, 1, 1, n, y, a);
		}
	}
}
