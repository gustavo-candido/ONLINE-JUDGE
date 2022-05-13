#include <bits/stdc++.h>
#define INF 1e18
using namespace std;

typedef  long long int ll;

ll mini, maxi;
int p, q;

inline void f(ll num, int sz) {
	if(sz == p) {
		if(num % (1<<q) == 0) {
			mini = min(mini, num);
			maxi = max(maxi, num);
		}
		return;
	}
	f(num*10+1,sz+1);
	f(num*10+2,sz+1); 
}

int main()
{
	int T, C=1;

	scanf("%d", &T);

	while(T--) {
		scanf("%d %d", &p, &q);
		mini = INF;
		maxi = -INF;
		f(0, 0);
		printf("Case %d: ", C++);
		if(mini == INF && maxi == -INF) printf("impossible\n");
		else if(mini == maxi) printf("%lld\n", maxi);
		else if(mini == INF && maxi != -INF) printf("%lld\n", maxi);
		else if(mini != INF && maxi == -INF) printf("%lld\n", mini);
		else printf("%lld %lld\n", mini, maxi);
	}
}
