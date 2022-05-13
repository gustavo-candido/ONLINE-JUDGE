#include <bits/stdc++.h>
#define left(x) x << 1
#define right(x) (x<<1)+1
#define mid(x,y) (x+y)/2
#define UP_SET 1
#define UP_CLR 2
#define UP_FLP 3

using namespace std;
typedef vector<int> vi;
vi island, tree, lazy;

int inverte(int i) {
	if(i == UP_SET) return UP_CLR;
	if(i == UP_CLR) return UP_SET;
	if(i == UP_FLP) return 0;
	return UP_FLP;
}
void propaga(int node, int st, int e) {
	if(lazy[node] == 0) return;
	if(lazy[node] == UP_SET) tree[node] = e-st+1;
	else if(lazy[node] == UP_CLR) tree[node] = 0;
	else if(lazy[node] == UP_FLP) tree[node] = (e-st+1) - tree[node];
	if(st != e) {
		int L = left(node), R = right(node), M = mid(st,e);
		if(lazy[node] == UP_SET || lazy[node] == UP_CLR) {
			lazy[L] = lazy[R] = lazy[node];
		}
		else {
			lazy[L] = inverte(lazy[L]);
			lazy[R] = inverte(lazy[R]);
		}
	}
	lazy[node] = 0;
}

void build(int node, int st, int e) {
    if(st == e) tree[node] = island[st];
    else {
        int L = left(node), R = right(node), M = mid(st,e);
        build(L, st, M);
        build(R, M+1, e);
        tree[node] = tree[L] + tree[R];
    }
}

void on(int node, int st, int e, int l, int r) {
	 propaga(node,st,e);
	 if(st > r || e < l) return;
	 if(st == e) {tree[node] = 1; return;}

	 int L = left(node), R = right(node), M = mid(st,e);
	 if(l <= st && r >= e) {
		tree[node] = e-st+1;
		lazy[L] = lazy[R] = UP_SET;
		return;
	 }
	 else {
		on(L, st, M, l, r);
		on(R, M+1,e, l, r);
		tree[node] = tree[L] + tree[R];
	}
}

void off(int node, int st, int e, int l, int r) {
	 propaga(node,st,e);
	 if(st > r || e < l) return;
	 if(st == e) {tree[node] = 0; lazy[node] = 0;return;}

	 int L = left(node), R = right(node), M = mid(st,e);
	 if(l <= st && r >= e) {
		tree[node] = 0;
		lazy[L] = lazy[R] = UP_CLR;
	 }
	 else {
		off(L, st, M, l, r);
		off(R, M+1,e, l, r);
		tree[node] = tree[L] + tree[R];
	}
}

void flip (int node, int st, int e, int l, int r) {
	 propaga(node,st,e);
	 if(st > r || e < l) return;
	 if(st == e) {tree[node] = tree[node] == 1 ? 0:1; return;}

	 int L = left(node), R = right(node), M = mid(st,e);
	 if(l <= st && r >= e) {
		tree[node] = (e-st+1) - tree[node];
		lazy[L] = inverte(lazy[L]);
		lazy[R] = inverte(lazy[R]);
		return;
	 }
	 else {
		flip(L, st, M, l, r);
		flip(R, M+1,e, l, r);
		tree[node] = tree[L] + tree[R];
	}
}

int sum(int node, int st, int e, int l, int r) {
    if(st > r || e < l) return 0;
    propaga(node, st, e);
    if(l <= st && e <= r) return tree[node];

    int L = left(node), R = right(node), M = mid(st,e);
    int p1 = sum(L, st, M, l, r);
    int p2 = sum(R, M+1, e, l, r);
    return p1+p2;

}
int main()
{
    int T, t, p, q;
    string aux;
    cin >> T;

    for(int C=1; C<=T; C++) {
	printf("Case %d:\n", C);
        island.clear();
        cin >> t;island.push_back(-1);
        while(t--) {
            cin >> p;getchar();
            cin >> aux;
            for(int i=0; i<p; i++) {
                for(int j=0; j<aux.size(); j++)
                        island.push_back(aux[j]-'0');
            }
        }

        tree.resize(4*island.size());
        lazy.assign(4*island.size(), 0);
        build(1, 1, island.size()-1);
        cin >> t;getchar();
	int c=1;
        while(t--) {
            cin >> aux >> p >> q;getchar(); p++; q++;
                 if(aux == "F") on(1, 1, island.size()-1, p, q);
            else if(aux == "E") off(1, 1, island.size()-1, p, q);
            else if(aux == "I") flip(1, 1, island.size()-1, p, q);
            else if(aux == "S") printf("Q%d: %d\n", c++, sum(1, 1, island.size()-1, p, q));
        }
    }
}
