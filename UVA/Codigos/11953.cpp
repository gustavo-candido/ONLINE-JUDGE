#include <bits/stdc++.h>
using namespace std;

char sea[111][111];
int R, C;

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

bool invalid(int i,int j) {
	return (i < 0 || i>= R || j < 0 || j >= C || (sea[i][j] != 'x' && sea[i][j] != '@'));
}	

void ff(int r, int c) {
	sea[r][c] = 'g';
	for(int i=0; i<4; i++) {
		if(!invalid(r+dr[i], c+dc[i])) ff(r+dr[i], c+dc[i]);
	}
}
int main()
{
	int t, Z=1;
	cin >> t;

	while(t--) {
		scanf("%d", &R);getchar();
		C = R;

		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				scanf("%c", &sea[i][j]);
			} getchar();
		}
		int ans=0;
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(sea[i][j] == 'x') {
					ans++;
					ff(i, j);
				}
			}
		}
		printf("Case %d: %d\n", Z++, ans);
	}
}
