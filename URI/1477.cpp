#include <bits/stdc++.h>
#define F first.first
#define S first.second
#define T second
#define left(x) x << 1
#define right(x) (x << 1) + 1
#define mid(x, y) (x+y) >> 1
#define _n 100005
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

iii tree[4*_n];
int lazy[4*_n];

iii join(iii a, iii b) {
    return iii(ii(a.F+b.F,a.S+b.S), a.T+b.T);
}

iii change(int i, iii A) {
    if(i == 0) return A;
    int a = A.F;
    int b = A.S;
    int c = A.T;

    A.F = c;
    A.S = a;
    A.T = b;

    return change(i-1, A);
}

void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = iii(ii(1,0),0);
        return;
    }

    int L = left(node);
    int R = right(node);
    int M = mid(l, r);

    build(L, l, M);
    build(R, M+1, r);
    tree[node] = join(tree[L], tree[R]);
}

void upp(int node, int l, int r, int a, int b) {
    if(lazy[node]) {
        tree[node] = change(lazy[node], tree[node]);
        if(l != r) {
            int L = left(node);
            int R = right(node);
            lazy[L] = (lazy[L]+lazy[node])%3;
            lazy[R] = (lazy[R]+lazy[node])%3;
        }
        lazy[node] = 0;
    }

    if(r < a || l > b) return;
    if(l >= a && r <= b) {
         tree[node] = change(1, tree[node]);
        if(l != r) {
            int L = left(node);
            int R = right(node);
            lazy[R] = (lazy[R]+1)%3;
            lazy[L] = (lazy[L]+1)%3;
        }
        lazy[node] = 0;
        return;
    }

    int L = left(node);
    int R = right(node);
    int M = mid(l, r);

    upp(L, l,   M, a, b);
    upp(R, M+1, r, a, b);

    tree[node] = join(tree[L], tree[R]);
    return;
}

iii query(int node, int l, int r, int a, int b) {
    if(lazy[node]) {
        tree[node] = change(lazy[node], tree[node]);
        if(l != r) {
            int L = left(node);
            int R = right(node);
            lazy[L] = (lazy[L]+lazy[node])%3;
            lazy[R] = (lazy[R]+lazy[node])%3;
        }
        lazy[node] = 0;
    }

    if(r < a || l > b) return iii(ii(0,0), 0);
    if(l >= a && r <= b) {
        return tree[node];
    }

    int L = left(node);
    int R = right(node);
    int M = mid(l, r);

    iii p1 = query(L, l  , M, a, b);
    iii p2 = query(R, M+1, r, a, b);
    return join(p1, p2);
}

int main()
{
    int n, q;

    while(scanf("%d %d", &n, &q) == 2) {
        getchar();

        n++;
        memset(lazy, 0, sizeof(int)*4*n);
        n--;
        build(1, 1, n);
        while(q--) {
            char op;
            int a, b;

            scanf("%c %d %d", &op, &a, &b);
            getchar();

            if(op == 'M') {
                upp(1, 1, n, a, b);
            }
            else {
                iii ans = query(1, 1, n, a, b);
                printf("%d %d %d\n", ans.F, ans.S, ans.T);
            }
        }
        puts("");
    }
}
