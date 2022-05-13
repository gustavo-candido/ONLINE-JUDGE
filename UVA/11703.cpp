#include <bits/stdc++.h>
using namespace std;

int main()
{
	int dp[1000005], maxi=1, n;
	double aux;
	dp[0] = 1;

	while(scanf("%d", &n) && n != -1) {
		if(maxi <= n) {
			while(maxi <= n) {
				aux = maxi;
				dp[maxi] = (dp[(int)(aux - sqrt(aux))] + dp[(int)log(aux)] + dp[(int)(aux*sin(aux)*sin(aux))]) % 1000000;
				maxi++;
			}
		} 
		printf("%d\n", dp[n]);
		
	}
}
