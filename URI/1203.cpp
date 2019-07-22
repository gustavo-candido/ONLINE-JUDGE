#include <bits/stdc++.h>
using namespace std;

int n, k, grau[102];
bool dp[10004];

int main()
{
    while(scanf("%d %d", &n, &k)!= EOF) {
        int o, d;

        memset(grau, 0, sizeof grau);
        memset(dp, 0, sizeof dp);
        for(int i=0; i<k; i++) {
            scanf("%d %d", &o, &d);
            grau[--o]++;
            grau[--d]++;
        }

        dp[0]= 1;
        for(int i=0; i<n; i++) {
            for(int j=k; j>=0; j--) {
                if(j-grau[i] >= 0) dp[j]|=dp[j-grau[i]];
            }
        }

        printf("%c\n", (dp[k])?'S':'N');
    }
}
