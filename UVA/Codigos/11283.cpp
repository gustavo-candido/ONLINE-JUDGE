#include <bits/stdc++.h>
using namespace std;

char grid[5][5], P[25], vis[5][5];
int m;
int dr[] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int pts(int tam) {
	if(tam == 3 || tam == 4) return 1;
	else if(tam == 5) return 2;
	else if(tam == 6) return 3;
	else if(tam == 7) return 5;
	else if(tam >= 8) return 11;
	return 0;
}

bool next(int r, int c, int tam) {
	if(r < 0 || r >= 4 || c < 0 || c >=4 || tam >= m || grid[r][c] != P[tam] || grid[r][c] == '*') return false;
	char aux = grid[r][c];
	grid[r][c] = '*';
	if(tam == m-1) {grid[r][c] = aux;return true;}

    bool ans = false;
	for(int i=0; i<8; i++) {
		ans = next(r+dr[i], c+dc[i], tam+1);
		if(ans) break;
	}
	grid[r][c] = aux;
	return ans;
}

int find() {
	int tam=0;
	bool f=false;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
            f = next(i,j,0);
            if(f) {
                i=4;j=4;tam = m;}
        }
    }
	return tam;
}
int main()
{
	int T, ans, n;
	scanf("%d", &T);
	getchar();
	for(int C=1; C<=T; C++) {
	    getchar();
		ans = 0;
		for(int i=0; i<4; i++) {
			scanf("%s", grid[i]);
			getchar();
		}
		scanf("%d", &n);
		getchar();
		while(n--) {
			scanf("%s", P);
			m = strlen(P);
			ans+=pts(find());
		}
		printf("Score for Boggle game #%d: %d\n", C,ans);
	}
}
