#include <bits/stdc++.h>

using namespace std;

int main ()
{
	long long int n, k;
	double dig;
	
	while(scanf("%lld %lld", &n, &k) != EOF) {
		if (!(k > n-k)) k = n-k;
		dig=0;
		for(int i=k+1; i<=n; i++) {
			dig+= log10(i) - log10(n-i+1);
		}
		dig = floor(dig)+1;
		printf("%.0f\n", dig);
	}
}
