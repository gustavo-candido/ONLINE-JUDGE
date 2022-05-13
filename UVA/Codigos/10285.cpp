#include <bits/stdc++.h>
using namespace std;
 
int R, C;
int grid[200][200];
int mem[200][200];
 
 
int run (int r, int c)
{
    if (mem[r][c] != -1) return mem[r][c];
	int A,B,C,D;
    A = B = C = D = 0;
 
    if ( r != 0 && grid [r - 1] [c] < grid [r] [c] )
        A = run (r - 1, c) + 1;
 
    if ( r != R - 1 && grid [r + 1] [c] < grid [r] [c] ) 
        B = run (r + 1, c) + 1;
 
    if ( c != 0 && grid [r] [c - 1] < grid [r] [c] ) 
        D = run (r, c - 1) + 1;
 
    if ( c != C - 1 && grid [r] [c + 1] < grid [r] [c] ) 
        C = run (r, c + 1) + 1;
 
    return mem [r] [c] = max (A, max (B, max (C, D)));
}
 
 
int main ()
{
    int N;
    char A[100];
    scanf ("%d", &N);
 
    while (N--) {
         memset (mem, -1, sizeof (mem));
        scanf ("%s %d %d", A, &R, &C);
         
        for ( int i = 0; i < R; i++ ) {
            for ( int j = 0; j < C; j++ )
                scanf ("%d", &grid[i][j]);
        }
 
        int maxi = -1000000;
 
        for ( int i = 0; i < R; i++ ) {
            for ( int j = 0; j < C; j++ ) {
                maxi = max(maxi,run(i,j));
            }
        }
 
        printf ("%s: %d\n", A, maxi + 1);
    }
 
    return 0;
}
