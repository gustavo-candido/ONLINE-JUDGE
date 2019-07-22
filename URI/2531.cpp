#include <bits/stdc++.h>
#define INF 100000008
#define middle(i,j) ((i+j)>>1)
#define left(x) (x<<1)
#define right(x) ((x<<1)+1) 
using namespace std;

const int N = 100005;

int tree[2][4*N];
int n, q;


void upp(int node, int i, int j, int k, int val) {
	if(i == j && i == k) {
		tree[0][node] = tree[1][node] = val; 
		return;
	}

	if(i>k || j<k) return;

	int l = left(node);
	int r = right(node);
	int mid = middle(i,j);

	upp(l, i, mid, k, val);
	upp(r, mid+1, j, k, val);

	tree[0][node] = min(tree[0][l], tree[0][r]);
	tree[1][node] = max(tree[1][l], tree[1][r]);

}


pair<int,int> query(int node, int i, int j, int a, int b) {
	if(j<a || i>b) return {INF,-INF};
	if(a<=i && j<=b) return {tree[0][node],tree[1][node]};


	int l = left(node);
	int r = right(node);
	int mid = middle(i,j);
	pair<int,int> p1,p2;

	p1 = query(l, i, mid, a, b);
	p2 = query(r, mid+1, j, a, b);

	return {min(p1.first,p2.first), max(p1.second, p2.second)};

}

int main()
{
	while(scanf("%d", &n) != EOF) {
		for(int i=0; i<N; i++){
			tree[0][i] = INF;
			tree[1][i] = -INF;
		}

		for(int i=1; i<=n; i++){
			int x;

			scanf("%d", &x);

			upp(1, 1, n, i, x);
		}

		int q;
		pair<int,int> pp;

		scanf("%d", &q);

		while(q--) {
			int op, l, r;

			scanf("%d %d %d", &op, &l, &r);

			if(op == 1) upp(1, 1, n, l, r);
			else{
				pp = query(1, 1, n, l, r);
				printf("%d\n", pp.second - pp.first);	
			} 


		}
 	}
}