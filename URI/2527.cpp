#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int  N, V;
long double dp[6001][6001], power[1005];

int main()
{
    power[0] = 1;
    N = 1000;
    V = 6000;
    for(int i=1; i<=1000; i++) power[i] = power[i-1]*6.0;

    for(int i=0; i<=N; i++) {
        for(int j=0; j<=6*N; j++) {
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int k=1; k<=N; k++) {
        for(int sum=6*N; sum>=0; sum--) {
            for(int i=1; i<7; i++) {
                if(k && sum-i>=0 && dp[k-1][sum-i]) dp[k][sum]+=dp[k-1][sum-i];
            }
        }
    }
    while(scanf("%d %d", &N, &V) != EOF) {
       long double aux=0;
       for(int i = V; i<=N*6; i++) aux+=dp[N][i];

        cout.precision(4);
        cout << fixed << aux/power[N] << endl;
    }
}
