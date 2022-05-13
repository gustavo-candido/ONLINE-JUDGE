#include <bits/stdc++.h>
#define _n 22
#define INF 1e10
using namespace std;

typedef long long int ll;

int main()
{
	ll f[_n], c[_n], n;

	scanf("%lld", &n);

	for(int i=0; i<n; i++)  scanf("%lld %lld", &f[i], &c[i]);
	

	ll q,flow, t, ans, aux, cost, dam;
	
	scanf("%lld", &q);
	for(int C=1; C<=q; C++) {
		ans = INF;
		scanf("%lld %lld",&flow, &t);
		
		for(int bit = 0; bit < (1<<n); bit++) {
			cost =  dam = 0;
			for(int i=0; i<n; i++) {
				if(bit & (1<<i)) cost+=c[i], dam+=f[i];
			}
			if(dam*t >= flow) ans = min(ans, cost);
		}
		printf("Case %d: ", C);
		if(ans == INF) puts("IMPOSSIBLE");
		else printf("%lld\n", ans);
	}
}
