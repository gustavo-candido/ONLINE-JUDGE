#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int>ii;
int t, grid[110][110], r, c, m, n, w, x, y, vis[110][110], C=1;

bool invalid(int i, int j) {
	return (i < 0 || i >= r || j < 0 || j >= c || vis[i][j] == 2);
}


void ff(int i, int j) {
	grid[i][j]++;
	if(vis[i][j] != 0) return;
	vis[i][j] = 1;
	set<ii> err;
	if(!invalid(i+m, j+n) && !err.count(ii(i+m, j+n)) ){err.insert(ii(i+m, j+n));ff(i+m, j+n);}
	if(!invalid(i+m, j-n) && !err.count(ii(i+m, j-n)) ){err.insert(ii(i+m, j-n));ff(i+m, j-n);}
	if(!invalid(i-m, j+n) && !err.count(ii(i-m, j+n)) ){err.insert(ii(i-m, j+n));ff(i-m, j+n);}
	if(!invalid(i-m, j-n) && !err.count(ii(i-m, j-n)) ){err.insert(ii(i-m, j-n));ff(i-m, j-n);}
	if(!invalid(i+n, j+m) && !err.count(ii(i+n, j+m)) ){err.insert(ii(i+n, j+m));ff(i+n, j+m);}
	if(!invalid(i+n, j-m) && !err.count(ii(i+n, j-m)) ){err.insert(ii(i+n, j-m));ff(i+n, j-m);}
	if(!invalid(i-n, j+m) && !err.count(ii(i-n, j+m)) ){err.insert(ii(i-n, j+m));ff(i-n, j+m);}
	if(!invalid(i-n, j-m) && !err.count(ii(i-n, j-m)) ){err.insert(ii(i-n, j-m));ff(i-n, j-m);}
	err.clear();
}
int main()
{
	

	scanf("%d", &t);

	while(t--) {
		scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
		memset(grid, 0, sizeof grid);
		memset(vis, 0, sizeof vis);
		for(int i=0; i<w; i++) {
			scanf("%d %d", &x, &y);
			vis[x][y] = 2;
		}
		int par=0, impar=0;
		ff(0, 0);
		grid[0][0]++;
		for(int i=0; i<r; i++) {
			for(int j=0; j<c; j++) {
				if(vis[i][j] == 1) {
					if(grid[i][j] % 2 == 0) par++;	
					else impar++;
				}
			}
		}
		printf("Case %d: %d %d\n", C++, par, impar);
	}
}

