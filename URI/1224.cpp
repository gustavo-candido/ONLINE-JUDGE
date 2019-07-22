#include <bits/stdc++.h>
using namespace std;

const int N = 20004;

long long v[N], dp[2][N];
int ant=1, att=0, n;

int main() {
    
    while(scanf("%d", &n) != EOF) {
   
        for(int i=0; i<n; i++) scanf("%lld", &v[i]);   
        for(int i=0; i<n; i++) dp[ant][i] = max(v[i], v[i+1]);

        for(int k=4; k<=n; k+=2) {
            for(int i=0; i<n; i++){
                int j = i+k-1;
                dp[att][i] = v[i] + min(dp[ant][i+1], dp[ant][i+2]);
                dp[att][i] = max(dp[att][i], v[j] + min(dp[ant][i+1], dp[ant][i]));
            }
            att^=1;
            ant^=1;
        } 

        printf("%lld\n", dp[ant][0]);
    }
}
