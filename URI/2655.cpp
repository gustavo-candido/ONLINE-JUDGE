#include <bits/stdc++.h>
#define lsb(x) (x&(-x))
using namespace std;

typedef long long int ll;
const int N = 100005;

ll tree[N<<2];
int v[N];

void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = (1LL<<v[l]);
        return;
    }

    int nxt = node<<1;
    int mid = (l+r)>>1;

    build(nxt, l, mid);
    build(nxt+1, mid+1, r);

    tree[node] = 0;
    tree[node]|=tree[nxt];
    tree[node]|=tree[nxt+1];
}

void update(int node, int l, int r, int pos, int val) {
    if(r < pos || pos < l) return;
    if(l == r) {
        tree[node] = (1LL<<val);
        return;
    }

    int nxt = node<<1;
    int mid = (l+r)>>1;

    update(nxt, l, mid, pos, val);
    update(nxt+1, mid+1, r, pos, val);

    tree[node] = 0;
    tree[node]|=tree[nxt];
    tree[node]|=tree[nxt+1];
}


ll query(int node, int l, int r, int a, int b) {
    if(a > r || b < l) return 0;
    if(a <= l && r <= b) return tree[node];

    int nxt = node<<1;
    int mid = (l+r)>>1;

    ll p1 = query(nxt, l, mid, a, b);
    ll p2 = query(nxt+1, mid+1, r, a, b);

    return p1|p2;
}

int main()
{
    int n, q, m;
    scanf("%d %d %d", &n, &q, &m);

    for(int i=1; i<=n; i++)
        scanf("%d", &v[i]);

    build(1,1,n);

    int op, l, r;
    while(q--) {
        scanf("%d %d %d", &op, &l, &r);

        if(op == 2) {
            update(1, 1, n, l, r);
        }
        else {
            ll ans = query(1, 1, n, l, r);

            printf("%d\n", __builtin_popcountll(ans));
        }
    }
}