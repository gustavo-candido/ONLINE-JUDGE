#include <bits/stdc++.h>
using namespace std;
 
const int N = 2003;
 
bool palindrome[N][N];
int n, dp[N];
string s;
 
 
void dp_pal() {
	memset(palindrome, false, sizeof palindrome);
 
	for(int i=0; i<n; i++) palindrome[i][i] = true;
		for(int i=0; i<n-1; i++) 
			if(s[i] == s[i+1]) palindrome[i][i+1] = true;
 
	for(int k=3; k<=n; k++) {
		for(int i=0; i<n; i++) {
			int j = i+k-1;
			if(j>=n) break;
			if(s[i] == s[j] && palindrome[i+1][j-1]) palindrome[i][j] = true;
		}
	}
}
 
void solve() {
	dp[0] = 0;
 
	for(int i=1; i<=n; i++) {
		dp[i] = N;
 
		for(int j=1; j<=i; j++) {
			if(palindrome[j-1][i-1] == true) {
				dp[i] = min(dp[i], dp[j-1]+1);
			}
		}
	}
 
}
 
int main()
{
	int teste=0;
 
	while(cin >> n && n != 0) {
		cin >> s;
 
		n = s.size();
 
		dp_pal();
		solve();
		printf("Teste %d\n%d\n\n", ++teste, dp[n]);
 
	}
} 