#include <bits/stdc++.h>
#define n_max 2007
using namespace std;


int min(int a, int b, int c) {
	return min(a, min(b, c));
}

int t, dp[n_max][n_max];
int main()
{
	
	string a, b;
	
	cin >> t;

	for(int i=0; i<n_max; i++) dp[i][0] = dp[0][i] = i;
	while(t--) {
		cin >> a >> b;
		
		int n = a.size()+1, m = b.size()+1;

		for(int i=1; i<n; i++) {
			for(int j=1; j<m; j++) {
				if(a[i-1] == b[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				}
				else dp[i][j] = min(dp[i-1][j], dp[i][j-1],dp[i-1][j-1])+1;
			}
		}
		
		printf("%d\n", dp[n-1][m-1]);
	}
}


