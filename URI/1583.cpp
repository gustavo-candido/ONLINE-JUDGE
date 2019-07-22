#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
queue<ii>q;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
int R, C;
char grid[70][70];

bool valid(int r, int c) {
    return !(r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != 'A');
}

void bfs()
{
    ii v;
    while(q.size()) {
        v = q.front(); q.pop();
        grid[v.first][v.second] = 'T';

        for(int i=0; i<4; i++)
            if(valid(v.first+dr[i], v.second+dc[i]))
                q.push( ii(v.first+dr[i], v.second+dc[i]) );
    }
}

int main()
{
    while(scanf("%d %d", &R, &C) && R && C) {
        getchar();
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == 'T')q.push(ii(i,j));
            }getchar();
        }
        bfs();
          for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                printf("%c", grid[i][j]);
            }puts("");
          }puts("");
    }
}
