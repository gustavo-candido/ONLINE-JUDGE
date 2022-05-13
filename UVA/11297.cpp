///USING 2D SEG_TREE
///O(log(n)²)
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

ii tree[4*_n][4*_n];
int v[_n][_n], xx, n;
bool leaf;

void build_y(int x, int node, int l, int r) {
	if(l == r) {
		if(leaf) {
			tree[x][node] = ii (v[xx][l], v[xx][l]); 
		}
		else {
			int L = left(x), R = right(x);
			tree[x][node].F = min(tree[L][node].F, tree[R][node].F);
			tree[x][node].S = max(tree[L][node].S, tree[R][node].S);
		}
		return;
	}
	int L = left(node), R = right(node), M = mid(l, r);
	
	build_y(x, L, l  , M);
	build_y(x, R, M+1, r);

	tree[x][node].F = min(tree[x][L].F, tree[x][R].F);
	tree[x][node].S = max(tree[x][L].S, tree[x][R].S);
}

void build_x(int node, int l, int r) {
	if(l == r) {
		leaf = 1;
		xx = l;
		build_y(node, 1, 1, n);
		return;
	}
	int L = left(node), R = right(node), M = mid(l, r);

	build_x(L, l  , M);
	build_x(R, M+1, r);
	leaf = 0;
	build_y(node, 1, 1, n);
}

void upp_y(int x, int node, int l, int r, int a, int val) {
	if(r < a || l > a) return;
	if(l == a && r == a) {
		if(leaf) {
			tree[x][node] = ii(val, val);
		}
		else {
			int L = left(x), R = right(x);
			tree[x][node].F = min(tree[L][node].F, tree[R][node].F);
			tree[x][node].S = max(tree[L][node].S, tree[R][node].S);
		}
		return;
	}
	int L = left(node), R = right(node), M = mid(l, r);

	upp_y(x, L, l  , M, a, val);
	upp_y(x, R, M+1, r, a, val);
	
	tree[x][node].F = min(tree[x][L].F, tree[x][R].F);
	tree[x][node].S = max(tree[x][L].S, tree[x][R].S);
}

void upp_x(int node, int l, int r, int a, int b, int val) {
	if(r < a || l > a) return;
	if(l == a && r == a) {
		leaf = 1;
		upp_y(node, 1, 1, n, b, val);
		return;
	}
	int L = left(node), R = right(node), M = mid(l, r);

	upp_x(L, l  , M, a, b, val);
	upp_x(R, M+1, r, a, b, val);
	leaf = 0;
	upp_y(node, 1, 1, n, b, val);
}

ii query_y(int x, int node, int l, int r, int a, int b){
	if(l > b || r < a) return ii(INF,-INF);
	if(a <= l && r <= b) return tree[x][node];
	int L = left(node), R = right(node), M = mid(l, r);
	ii p1 = query_y(x, L, l  , M, a, b);
	ii p2 = query_y(x, R, M+1, r, a, b);
	return ii(min(p1.F, p2.F), max(p1.S, p2.S));
}

ii query_x(int node, int l, int r, int ax, int bx, int ay, int by) {
	if(l > bx || r < ax) return ii(INF,-INF);
	if(ax <= l && r <= bx) return query_y(node, 1, 1, n, ay, by);	
	
	int L = left(node), R = right(node), M = mid(l, r);
	ii p1 = query_x(L, l  , M, ax, bx, ay, by);
	ii p2 = query_x(R, M+1, r, ax, bx, ay, by);
	return ii(min(p1.F, p2.F), max(p1.S, p2.S));
}

int main()
{
	scanf("%d", &n);

	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	build_x(1, 1, n);

	int q, x, y, a, b;
	ii ans;
	char op;
	scanf("%d", &q);
	getchar();
	while(q--) {
		scanf("%c", &op);

		if(op == 'q') {
			scanf("%d %d %d %d", &x, &y, &a, &b);
			getchar();
			ans = query_x(1, 1, n, x, a, y, b);
			printf("%d %d\n", ans.S, ans.F);
		}

		else {
			scanf("%d %d %d", &x, &y, &a);
			getchar();
			upp_x(1, 1, n, x, y, a);		
		}
	}
}
