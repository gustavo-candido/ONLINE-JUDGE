#include "bits/stdc++.h"
#define msb(x) __builtin_clz(1) - __builtin_clz(x) 
using namespace std;

typedef long long ll;

const int N = 100005, LOG = 17;

ll v[N];
int n, table[N][LOG]; 

int query(int a, int b) {
	int x = msb(b-a+1);

	if(v[table[a][x]] < v[table[b-(1<<x)+1][x]]) return table[a][x];
	return table[b-(1<<x)+1][x];
}

ll solve(int l, int r) { 
	if(l>r) return -1;
	if(l==r) return v[l];

	int idx = query(l, r);
	ll a = (r-l+1)*v[idx], b=0, c=0;
	if(idx != l) b = solve(l, idx-1);
	if(idx != r) c = solve(idx+1, r);

	return max(a,max(b,c)); 
}

int main(){

	while(scanf("%d", &n) && n) {
		for(int i=0; i<n; i++)
			scanf("%lld", &v[i]);

		for(int i=0; i<n; i++) table[i][0] = i;

		for(int j=1; j<LOG; j++) {
			for(int i=0; i+(1<<(j-1))<n; i++) {
				if(v[table[i][j-1]] < v[table[i+(1<<(j-1))][j-1]]) table[i][j] = table[i][j-1];
				else table[i][j] = table[i+(1<<(j-1))][j-1];
			}
		}

		printf("%lld\n", solve(0, n-1));
	}
}