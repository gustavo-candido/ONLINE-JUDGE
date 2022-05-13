#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int>iii;
int main()
{
	int n, m, a, b, c, g[10], x, y, z;
	iii v[21];
	bool f;
	while(scanf("%d %d", &n, &m) && n+m) {
		for(int i=0; i<n; i++) g[i] = i; 
		for(int i=0; i<m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			v[i] = iii(ii(a,b), c);
		}
		int ans = 0;
		do {
		  f = true;
		  for(int i=0; i<m; i++) {
			a = v[i].F.F;
			b = v[i].F.S;
			c = v[i].S;
			for(int j=0; j<n; j++) {
				if(g[j] == a) x = j;
				if(g[j] == b) y = j;
			}
			
			if(!((c < 0 && abs(x-y) >= abs(c)) || (c > 0 && abs(x-y) <= c))) f = false, i = 50; 
		  }
		  if(f) ans++;
		} while(next_permutation(g, g+n));
		printf("%d\n", ans);
	}
	
}
