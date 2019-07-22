#include <bits/stdc++.h>
#define _n 1005
using namespace std;

int dp[_n][_n], K, n, m, *p, *x;
char a[_n], b[_n];

int main()
{
    p = &dp[0][0];
    for(int i=0; i<=_n; i++) {*p = 0; p+=_n;}
    p = &dp[0][0];
    for(int i=0; i<=_n; i++) {*p = 0; p++;}

    while(scanf("%d", &K) && K) {
        getchar();
        scanf("%s %s", a, b);
        n = strlen(a);
        m = strlen(b);

        p = &dp[1][1];
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++, p++) {
                if(a[i-1] == b[j-1]) {
                    int ans = -1;
                    x = p;
                    for(int k=1; i>=k && j>=k; k++) {
                        if(a[i-k] != b[j-k]) break;
                        x-=_n+1;
                        if(k >= K) {
                            ans = max(ans, *x+k);
                        }

                    }
                    *p = max(ans, max(*(p-_n), *(p-1)));
                }
                else *p = max(*(p-_n), *(p-1));
            }
            p+=_n-m;
        }
        printf("%d\n", dp[n][m]);
    }
}
