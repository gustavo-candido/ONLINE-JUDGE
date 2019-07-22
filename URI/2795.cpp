#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;

const int N = 402;

char s[N];
int cost[N][N], dp[N][N], n, m;

int f(char a, char b) {
	if(a>b)swap(a,b);
	return min(b-a, 'z'-b+a-'a'+1);
}

int main()
{
	scanf("%d %d", &n, &m);

	getchar();

	scanf("%s", s);

	for(int i=0; i<n; i++) cost[i][i] = 0;
	for(int i=0; i+1<n; i++) cost[i][i+1] = f(s[i],s[i+1]);

	for(int k=3; k<=n; k++) {
		for(int i=0; i<n; i++) {
			int j = i+k-1;
			if(j>n)continue;
			cost[i][j] = f(s[i], s[j]) + cost[i+1][j-1];
		}
	}

	for(int j=0; j<n; j++) dp[0][j] = cost[0][j];
	for(int k=1; k<m; k++) {
		for(int j=0; j<n; j++) {
			dp[k][j] = cost[0][j];
			for(int i=0; i<j; i++) {
				dp[k][j] = min(dp[k][j], dp[k-1][i]+cost[i+1][j]);
			}
		}
	}

	printf("%d\n", dp[m-1][n-1]);
}