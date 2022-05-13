#include <bits/stdc++.h>
using namespace std;
int R, C, x;
int dr[] = {-1,  0, 1, 0};
int dc[] = { 0, -1, 0, 1};
char box[100][100];

int fill(int r, int c, char c1, char c2) {
	if(r < 0 || r >= R) return 0;
	if(c < 0) c = C-1;
	if(c == C) c=0;
	if(box[r][c] != c1) return 0;
	int ans = 1;
	box[r][c] = c2;
	for(int i=0; i<4; i++) {
		ans+= fill(r+dr[i], c+dc[i], c1, c2);
	}
	return ans;
}

int main ()
{
	int r, c;
	char c1, c2;
	while(scanf("%d %d", &R, &C) != EOF) {
		getchar();
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) scanf("%c", &box[i][j]);
			getchar();
		}
		scanf("%d %d", &r, &c);
		c1 = box[r][c];
		(c1 == '.') ? c2 = '|':
		fill(r, c, c1, c2);
		x = 0;
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(box[i][j] == c1) {
					x = max(x, fill(i, j, c1, c2));
				}
			}
		}
		printf("%d\n", x);
	}
}
