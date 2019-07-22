#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) (x<<1)+1
#define mid(x, y) (x+y)/2
using namespace std;

typedef long long int lld;

lld tree[400040], lazy[400040];

lld sum(lld node, lld st, lld e, lld l, lld r) {
	if(lazy[node] != 0) {
		lld L = left(node), R = right(node);
		tree[node]+=lazy[node]*(e-st+1);
		if(st != e) {
			lazy[L]+=lazy[node];
			lazy[R]+=lazy[node];
		}
		lazy[node] = 0;
	}
	if(st >= l && e <= r) return tree[node];
	if(st > r || e < l) return 0;
	lld M = mid(st, e), L = left(node), R = right(node);
	lld p1 = sum(L, st, M, l, r);
	lld p2 = sum(R, M+1, e, l, r);
	return p1+p2;
}

void upp(lld node, lld st, lld e, lld l, lld r, lld val) {
	lld M = mid(st, e), L = left(node), R = right(node);
	if(lazy[node] != 0) {
		tree[node]+=lazy[node]*(e-st+1);
		if(st != e) {
			lazy[L]+=lazy[node];
			lazy[R]+=lazy[node];
		}
		lazy[node] = 0;
	}
	if(st > r || e < l) return;
	if(st >= l && e <= r) {
		tree[node]+=val*(e-st+1);
		if(st != e) {
			lazy[L]+=val;
			lazy[R]+=val;
		}
	}
	else {
		upp(L, st, M, l, r, val);
		upp(R, M+1, e, l, r, val);
		tree[node] = tree[L] + tree[R];
	}
}

int main()
{
	lld T, N, C, op, p, q, v;
	scanf("%lld", &T);

	while(T--) {
		scanf("%lld %lld", &N, &C); N++;
		memset(tree, 0, sizeof(lld)*N*4);
		memset(lazy, 0, sizeof(lld)*N*4); N--;
		while(C--) {
			scanf("%lld %lld %lld", &op, &p, &q);
			if(op == 0) {
				scanf("%lld", &v);
				upp(1, 1, N, p, q, v);
			}
			else printf("%lld\n", sum(1, 1, N, p, q));
		}
	}
}
