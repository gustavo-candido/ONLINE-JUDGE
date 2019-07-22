#include <bits/stdc++.h>
using namespace std;

typedef  double ll ;

ll dp[20];
ll fat(int  i) {
	if(i == 1.0) return 1.0;
	if(dp[i] != 0) return dp[i];
	else return dp[i] = i * fat(i-1.0); 
}

int main()
{
	string s;
	
	memset(dp, 0, sizeof(dp));
	while(cin >> s) {
		if(s == "0") break;
		printf("%.0lf\n", fat(s.size()));
	}
}