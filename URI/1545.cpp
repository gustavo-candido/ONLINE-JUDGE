#include <bits/stdc++.h>
#define _n 10005
using namespace std;

typedef long long int ll;
ll dp[_n][3];
int n, vet[_n];

int main()
{
    while(scanf("%d", &n)!= EOF) {
       for(int i=0; i<n; i++) scanf("%d", &vet[i]);

       int u=0, v=1, k=2;

       if(n == 2) dp[n-1][u] = max(vet[0], vet[1]);
       else {

           for(int i=n-4; i>=0; i--) {
                dp[i+1][u] = max(vet[i], vet[i+1]);
                dp[i+2][v] = max(vet[i+1], vet[i+2]);
                dp[i+3][k] = max(vet[i+2], vet[i+3]);

                for(int j=i+3; j<n; j+=2) {
                    ll p1 = vet[i] + max(dp[j][k], dp[j-1][v]);
                    ll p2 = vet[j] + max(dp[j-1][v], dp[j-2][u]);
                    dp[j][u] = max(p1, p2);
                }

                if(i-1 >= 0) {
                    u--; if(u < 0) u = 2;
                    v--; if(v < 0) v = 2;
                    k--; if(k < 0) k = 2;
                }
           }
       }
       printf("%lld\n", dp[n-1][u]);
    }
}

