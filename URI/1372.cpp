#include <bits/stdc++.h>
using namespace std;

int V[100005], v[100005], memo[100005], n, N, m;

int go(int *p) {
    int *dp = &memo[2];
    memo[0] = memo[1] = 0;

    for(int i=2; i<N+2; i++, p++, dp++) {
        *dp = max(*(dp-2)+*p, *(dp-1));
    }
    return *(dp-1);
}

int main()
{
    int *P, *p;
    while(scanf("%d %d", &n, &m) && n+m) {
        N = m;
        P = &V[0];
        for(int i=0; i<n; i++, P++) {
            p = &v[0];
            for(int j=0; j<m; j++) scanf("%d", p++);
            *P = go(&v[0]);
        }
        N = n;

        printf("%d\n", go(&V[0]));
    }
}
