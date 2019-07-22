#include <bits/stdc++.h>
using namespace std;

int  R, C, ans=0, d, r=0, c=0;
char m[105][105];
int dr[] = {-1,  0, 0, 1};
int dc[] = { 0, -1, 1, 0};

bool valid(int r, int c) {
    return !(m[r][c] == 'x' || r < 0 || r >= R || c < 0 || c >= C);
}

void dir(int r, int c) {
    if(m[r][c] == '^') d=0;
    else if(m[r][c] == '<') d=1;
    else if(m[r][c] == '>') d=2;
    else if(m[r][c] == 'v') d=3;
}
int main()
{
    cin >> C >> R; getchar();
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) cin >> m[i][j];
        getchar();
    }
    while(ans == 0) {
        if(valid(r, c)) {
            if(m[r][c] == '*') ans = 1;
            else if(m[r][c] != '.')dir(r,c);
        }
        else ans = -1;
        m[r][c] = 'x';
        r+=dr[d]; c+=dc[d];
    }
    if(ans == 1) puts("*");
    else puts("!");
}
