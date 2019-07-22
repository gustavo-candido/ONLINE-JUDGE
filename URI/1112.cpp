#include <bits/stdc++.h>
#define lbit(x) (x & (-x))  
using namespace std;

typedef long long int ll;
ll ft[1005][1005], X, Y;

void upp(ll x, ll b, ll val) {
	ll y;
	for(; x <= X; x+=lbit(x)) 
		for(y = b; y <= Y; y+=lbit(y)) ft[x][y]+=val;
}

ll sum(ll x, ll b) {
	ll y, ans=0;
	for(; x ; x-=lbit(x)) 
		for(y = b; y; y-=lbit(y)) ans+=ft[x][y];
	return ans;
}

ll sum (ll x, ll y, ll a,  ll b) {
	return sum(max(x, a), max(y, b)) - sum(max(x, a), min(y, b)-1) - sum(min(x, a)-1,max(y, b)) + sum(min(x, a)-1, min(y, b)-1); 
}

int main()
{
	ll x, y, a, b, p, q, n;
	char op;

	while(scanf("%lld %lld %lld", &X, &Y, &p) && (X+Y)){
		memset(ft, 0, sizeof ft);
		X++, Y++;

		scanf("%lld", &q); getchar();
		while(q--) {
			scanf("%c", &op);
			if(op == 'A') {
				scanf("%lld %lld %lld", &n, &x, &y);
				x++, y++;
				upp(x, y, n);
			}
			else {
				scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
				x++, y++, a++, b++;
				printf("%lld\n", sum(x, y, a, b)*p); 
			}
			getchar();
		}
		puts("");
	}
}