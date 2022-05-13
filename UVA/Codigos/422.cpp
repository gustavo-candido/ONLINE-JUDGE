#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

typedef struct ponto{
	int x, y;
} ponto;

int dr[] = {-1,-1,  0,  0, 1, 1, 1};
int dc[] = {-1, 1, -1, 1, -1, 0, 1};
struct ponto st, sf;
int N, m;
char grid[MAX][MAX], P[MAX];

bool next(int r, int c, int tam, int dir) {
	if(r < 0 || r >= N || c < 0 || c >= N || grid[r][c] != P[tam] || tam > m) return false;
	if(tam == m-1){sf.x = r+1; sf.y = c+1;return true;}
	return next(r+dr[dir], c+dc[dir], tam+1, dir);
}

bool find() {
	bool f = false;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(grid[i][j] == P[0]) {
				st.x = i+1;
				st.y = j+1;
				for(int k=0; k<8; k++) {
					f = next(i,j,0,k);
					if(f) {
						i=N; j=N; break;
					}
				}
			}
		}
	}
	return f;
}

int main()
{	
	scanf("%d", &N);
	getchar();
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			scanf("%c", &grid[i][j]);
		}
		getchar();
	}
	while(scanf("%s", P) && strcmp(P, "0") != 0) {
		m = strlen(P);
		if(find()){
			printf("%d,%d %d,%d\n", st.x, st.y, sf.x, sf.y);
		}
		else printf("Not found\n");
	}
}
