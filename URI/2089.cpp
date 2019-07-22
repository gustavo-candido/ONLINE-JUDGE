#include <bits/stdc++.h>
#define _v 100005
#define _n 1003
using namespace std;

int coin[_n], v, n;

bool dp[_v];

int main()
{
    while(scanf("%d %d", &v, &n) && v+n) {
        for(int i=0; i<n; i++)
            scanf("%d", &coin[i]);

        memset(dp, 0, sizeof(bool)*(v+1));
        dp[0] = 1;

        for(int i=0; i<n; i++) {
            for(int j=v; j>=0; j--) {
                if(j-coin[i] >= 0 && dp[j-coin[i]])dp[j] = 1;
            }
        }

        printf("%s\n", (dp[v] == 1)?"sim":"nao");
    }
}
