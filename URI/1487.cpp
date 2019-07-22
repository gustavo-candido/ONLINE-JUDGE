#include <bits/stdc++.h>
#define _n 102
#define _t 602
using namespace std;

int main()
{
    int n, t, w[_n], val[_n], dp[_t], C=0;

    while(scanf("%d %d", &n, &t) && n+t){
        for(int i=0; i<n; i++)
            scanf("%d %d", &w[i], &val[i]);

        memset(dp, 0, sizeof dp);

        for(int i=1; i<=t; i++) {
            for(int j=0; j<n; j++) {
                if(i-w[j] >= 0) dp[i] = max(dp[i], dp[i-w[j]]+val[j]);
            }
        }

        printf("Instancia %d\n", ++C);
        printf("%d\n", dp[t]);
        puts("");
    }
}
