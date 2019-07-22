#include<bits/stdc++.h>
using namespace std;

int dp[100005];
int seq(int i) {
    if(i == 1) return 2;
    if(dp[i] != -1) return dp[i];

    return dp[i] = i + seq(i-1);
}

int main()
{
    int t, i;

    scanf("%d", &t);

    memset(dp, -1, sizeof dp);
    while(t--) {
        scanf("%d", &i);
        printf("%d\n", seq(i));
    }
}
