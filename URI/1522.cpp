#include <bits/stdc++.h>
#define _n 105
using namespace std;


int n, dp[_n][_n][_n], box[_n][3], ans;

void f(int a, int b, int c) {

    if(a == n && b == n && c == n) {ans = 1; return;}
    if(a > n || b > n || c > n) return;
    if(dp[a][b][c] != -1) return;
    dp[a][b][c] = 1;

    if(box[a][0] % 3 == 0) f(a+1, b, c);
    if(box[b][1] % 3 == 0) f(a, b+1, c);
    if(box[c][2] % 3 == 0) f(a, b, c+1);

    if((box[a][0] + box[b][1]) % 3 == 0) f(a+1, b+1, c);
    if((box[a][0] + box[c][2]) % 3 == 0) f(a+1, b, c+1);
    if((box[b][1] + box[c][2]) % 3 == 0) f(a, b+1, c+1);

    if((box[a][0] + box[b][1] + box[c][2]) % 3 == 0) f(a+1, b+1, c+1);
}
int main()
{
        while(scanf("%d", &n) && n) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<3; j++) {
                    scanf("%d", &box[i][j]);
                }
            }
            memset(dp, -1, sizeof dp);
            ans = 0;
            f(0,0,0);
            printf("%d\n", ans);
        }

}
