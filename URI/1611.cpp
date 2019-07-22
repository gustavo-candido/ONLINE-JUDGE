#include <bits/stdc++.h>
#define _m 50004
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int t, n, c, m, v[_m], ans;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d %d", &n, &c, &m);

        for(int i=0; i<m; i++)
            scanf("%d", &v[i]);

        sort(v, v+m, cmp);

        ans = 0;

        for(int i=0; i<m; i+=c)  ans+=v[i]*2;
        printf("%d\n", ans);
    }
}
