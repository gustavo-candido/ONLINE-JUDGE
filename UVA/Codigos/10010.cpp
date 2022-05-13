#include <bits/stdc++.h>
#define MAXI 1000
using namespace std;

string P;
char grid[MAXI][MAXI];
int N, R, C, x, m;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0,  1, -1, 1, -1, 0, 1};

bool next(int r, int c, int tam, int dir) {
	if((r < 0 || r >= R || c < 0 || c >= C) || tam > m || grid[r][c] != P[tam]) return false;
	if(tam == m-1) return true;
	next(r+dr[dir], c+dc[dir], tam+1, dir);
}

void search() {
    bool f;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            f = false;
            for(int d=0; d<8; d++) {
                f = next(i, j, 0, d);
                if(f) {
                    cout << i+1 << " " << j+1 << endl;
                    i = R;
                    j = C;
                    break;
                }
            }
        }
    }
}

int main()
{

	cin >> N;
    bool f = false;
	while(N--) {
		cin >> R >> C;
        if(f) puts("");
		getchar();
		for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                scanf("%c", &grid[i][j]);
                grid[i][j] = tolower(grid[i][j]);
            }getchar();
        }

		cin >> x;
		getchar();
		while(x--) {
			cin >> P;
			for(int i=0; i<(int)P.size(); i++)P[i] = tolower(P[i]);
			m = P.size();
			search();
		}
		f = true;
	}
}
