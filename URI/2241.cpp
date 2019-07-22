#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p[505][505], b[505][505], n, m, x, y, c, d;

    scanf("%d %d", &n, &m);

    memset(p, 0, sizeof p);
    memset(b, 0, sizeof b);

    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
        p[x][y]=1;
    }
    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        x--; y--;
        b[x][y]=1;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>0){
                p[i][j]+=p[i-1][j];
                b[i][j]+=b[i-1][j];
            }
            if(j>0) {
                p[i][j]+=p[i][j-1];
                b[i][j]+=b[i][j-1];
            }
            if(i>0 && j>0){
                p[i][j]-=p[i-1][j-1];
                b[i][j]-=b[i-1][j-1];
            }
        }
    }

    x=y=0;

    for(int k=0; k<n; k++) {
        for(int i=0; i+k < n; i++) {
            for(int j=0; j+k < n; j++) {
                c = p[i+k][j+k];
                d = b[i+k][j+k];
                if(i>0) {
                    c-=p[i-1][j+k];
                    d-=b[i-1][j+k];
                }
                if(j>0) {
                    c-=p[i+k][j-1];
                    d-=b[i+k][j-1];
                }
                if(i>0 && j>0) {
                    c+=p[i-1][j-1];
                    d+=b[i-1][j-1];
                }
                if(c>0 && !d) x++;
                if(d>0 && !c) y++;
            }
        }
    }

    printf("%d %d\n", x, y);
}
