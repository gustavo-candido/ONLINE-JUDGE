#include <bits/stdc++.h>
#define lbit(x) (x&(-x))
#define _n 22
using namespace std;

int maxi, ans, n, m, v[_n], t, z, inter[1 << _n];

void print(int x) {
	for(int i=1; i<=m; i++) {
		if(x&(1<<i)) printf(" %d", i);
	}printf("\n");
}

void f(int x, int k, int u) {
	//printf(">>>> %d %d %d\n", x, k, u);
	if(u > n) return;
	//puts("Have:");
	//print(x);
	//puts("-----");
	if(k == m) {
		vector<int> vec;
		int aux=0, bit, s;
		for(int i=1; i<=n; i++) {
			if(x & 1<<i) vec.push_back(i), aux+=v[i];
		}
		for(int j=1; j <= 1<<k; j++) {
			bit=0;
			s = j;
			while(s-lbit(s)) {bit++;s-=lbit(s);}
			int index=0;
			for(int i=0; i<k; i++) {
				if(j&(1<<i)) index|=1<<vec[i];
			}
			aux-=(inter[index]*bit);
		}
		if(aux > maxi) {
			maxi = aux;
			ans = x;
		}
		return;
	} 
//	printf("Try | %d\n", u);
	f(x| 1 << u, k+1, u+1);
//	printf("Remove %d\n", u);
	f(x, k, u+1);
}
int main()
{
	int  x, aux, C=1;

	while(scanf("%d %d", &n, &m) && n+m) {
		if(C != 1) puts("");
		maxi = -1000000000;
		for(int i=1; i<=n; i++) scanf("%d", &v[i]);
		scanf("%d", &t);
		memset(inter, 0, sizeof inter);
		while(t--) {
			scanf("%d", &z);
			x=0;
			for(int i=1; i<=z; i++) {
				scanf("%d", &aux);
				x|=1<<aux;
			}
			scanf("%d", &aux);
			inter[x] = aux;
		}
		f(0, 0, 1);
		printf("Case Number %d\n", C++);
		printf("Number of Customers: %d\n", maxi);
		printf("Locations recommended:");
		for(int i=1; i<=n; i++) 
			if(ans & 1 << i) printf(" %d", i);
		puts("");
	}
}

