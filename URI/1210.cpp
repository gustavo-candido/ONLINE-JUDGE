#include <bits/stdc++.h>
#define INF 1000000009;
using namespace std;

const int N = 2001;

int dp[N][N], n, age, age_max, price, repair[N], sell[N];
vector<int> ans;

int go(int year, int k) {
    if(k > age_max) return INF;
    if(year > n) return 0;
    if(~dp[year][k]) return dp[year][k];

    return  dp[year][k] = min(go(year+1,1)+price+repair[0]-sell[k], go(year+1,k+1)+repair[k]); 
}

void path(int year, int k) {
    if(k > age_max) return;
    if(year > n) return;
    if(dp[year][k] == go(year+1,1)+price+repair[0]-sell[k]){
        ans.push_back(year);
        path(year+1,1);
    }
    else path(year+1,k+1);
}
int main(){
    while(scanf("%d %d %d %d", &n, &age, &age_max, &price)!= EOF) {
        for(int i=0; i<age_max; i++) scanf("%d", &repair[i]); repair[age_max] = INF;
        for(int i=1; i<=age_max; i++) scanf("%d", &sell[i]); sell[0] = -INF;

        memset(dp, -1, sizeof dp);
        printf("%d\n", go(1, age));
        ans.clear();
        path(1, age);
        if(ans.size() == 0) puts("0");
        else {
            printf("%d", ans[0]);
            for(int i=1; i<ans.size(); i++) printf(" %d", ans[i]);
            puts("");
        }
    }
}