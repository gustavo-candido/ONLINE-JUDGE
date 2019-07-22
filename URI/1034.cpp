#include <bits/stdc++.h>
#define _s 1000003
#define _n 30
using namespace std;

int t, n, s, v[_n], dp[_s];

int main()
{

        scanf("%d", &t);

        while(t--) {
            scanf("%d %d", &n, &s);

            for(int i=0; i<n; i++) {
                scanf("%d", &v[i]);
            }

            int aux;
            for(int i=0; i<n; i++) {
                for(int j=0; j<n-1; j++) {
                    if(v[j] > v[j+1]) {
                        aux = v[j];
                        v[j] = v[j+1];
                        v[j+1] = aux;
                    }
                }
            }
            if(n == 1) printf("%d\n", s);
            else{
                memset(dp, 0x3F3F3F3F, sizeof(int)*(s+1));
                dp[0] = 0;
                for(int i=0; i<=s; i++) {
                    for(int j=0; j<n; j++) {
                        if(i+v[j] > s) break;
                        dp[i+v[j]] = min(dp[i+v[j]],dp[i]+1);
                    }
                }
                printf("%d\n", dp[s]);
            }
        }
}