#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;

int main()
{
    int n, dp[1005], ans;
    ii v[1005];

    scanf("%d", &n);

    for(int i=0; i<n; i++) scanf("%d %d", &v[i].F, &v[i].S);

    sort(v, v+n, greater<ii>());

    for(int i=0; i<n; i++) {
        ans = v[i].S - v[i].F;
        for(int j=0; j<=i; j++) {
            if(v[j].F >= v[i].S) ans = max(ans, dp[j] +  v[i].S - v[i].F);
        }
        dp[i] = ans;
    }

    ans = 0;
    for(int i=0; i<n; i++) ans = max(ans, dp[i]);
    printf("%d\n", ans);
}
