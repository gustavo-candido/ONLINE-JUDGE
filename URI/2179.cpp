#include <bits/stdc++.h>
using namespace std;

int x, y, box[20][20], vis = 0, n, mov=1;
bool f= false;

bool valid() {

     if(!(x < 0 || x >= n || y < 0 || y >= n)) {
        vis++;
        if(f) printf(" ");
     }
    f = true;
    return !(x < 0 || x >= n || y < 0 || y >= n);
}
int main()
{

    cin >> n >> x >> y;

    int cont = 1, A, B, C, D;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            box[i][j] = cont;
            cont++;
        }
    }
    if(valid()) printf("%d", box[x][y]);
    A = B = 1;
    C = D = 2;
    while(vis < n*n) {
        for(int i=0; i<A; i++) {
            y++;
            if(valid()) printf("%d", box[x][y]);
            mov++;
            if(vis == n*n) break;
        }
        if(vis == n*n) break;
        A+=2;
        for(int i=0; i<B; i++) {
            x++;
            if(valid()) printf("%d", box[x][y]);
            mov++;
            if(vis == n*n) break;
        }
        if(vis == n*n) break;
        B+=2;
        for(int i=0; i<C; i++) {
            y--;
            if(valid()) printf("%d", box[x][y]);
            mov++;
            if(vis == n*n) break;
        }
        if(vis == n*n) break;
        C+=2;
        for(int i=0; i<D; i++) {
            x--;
            if(valid()) printf("%d", box[x][y]);
            mov++;
            if(vis == n*n) break;
        }
        D+=2;
    }
    printf("\n%d\n", mov);
}
