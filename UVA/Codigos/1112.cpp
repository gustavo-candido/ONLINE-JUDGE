#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define lsone(a) a&-a

ll n, m, p;
ll ft[1010][1010];

void update(int x, int y, int v){
	for(int i=x; i<=n; i+=lsone(i)){
		for(int j=y; j<=m; j+=lsone(j)){
			ft[i][j]+=v;
		}
	}
}

ll sum(int x, int y){
	ll ans = 0;
	for(int i=x; i>0; i-=lsone(i)){
		for(int j=y; j>0; j-=lsone(j)){
			ans+= ft[i][j];
		}
	}
	return ans;
}

int main(){
	while(scanf("%lld %lld %lld", &n, &m, &p)){
		if(!n && !m && !p) break;
		memset(ft, 0, sizeof ft);
		int q;
		ll x, y, xx, yy, v;
		char aux;
		scanf("%d", &q);
		while(q--){
			scanf(" %c", &aux);
			if(aux=='A'){
				scanf("%lld %lld %lld", &v, &x, &y);
				x++; y++;
				update(x, y, v);
				
			}else{
				scanf("%lld %lld %lld %lld", &x, &y, &xx, &yy);
				x++; xx++; y++; yy++;
				
				if(xx < x){
					swap(x, xx);
				}
				if(yy < y) swap(y, yy);
				
				
				ll ans = sum(xx, yy) - sum(xx, y-1) - sum(x-1, yy) + sum(x-1, y-1);
				printf("%lld\n", ans*p);
			}
		}
		printf("\n");
	}
}
