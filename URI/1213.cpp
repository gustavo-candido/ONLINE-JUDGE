#include <bits/stdc++.h>
using namespace std;

const int N = 10004;

int dp[N]; 


int main()
{
	memset(dp, -1, sizeof dp);

	int n;

	while(scanf("%d", &n) != EOF) {
		int x = 1, dig = 1;

		while(x%n) {
			if(dp[n] != -1) {
				dig = dp[n];
				break;
			}
			x%=n;
			x*=10;
			x++;
			dig++;
		} 
		dp[n] = dig;

		printf("%d\n", dig);

	}
}