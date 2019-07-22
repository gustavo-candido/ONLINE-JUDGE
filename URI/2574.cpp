#include<bits/stdc++.h>
using namespace std;

int mat[2050][2050], n, g, ans, aux;
bool f;

int main()
{
        scanf("%d %d", &n, &g);


        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &mat[i][j]);
                if(mat[i][j] < g) f = false;
                if(i>0) mat[i][j]+=mat[i-1][j];
                if(j>0) mat[i][j]+=mat[i][j-1];
                if(i>0 && j>0) mat[i][j]-=mat[i-1][j-1];
            }
        }

        for(int k=1; k<=n; k*=2) {
            ans = 0;
            f = true;
            for(int i=0; i+k<=n; i+=k) {
                for(int j=0; j+k<=n; j+=k) {
                    aux = mat[i+k-1][j+k-1];
                    if(i>0)aux-=mat[i-1][j+k-1];
                    if(j>0) aux-=mat[i+k-1][j-1];
                    if(i>0 && j>0) aux+=mat[i-1][j-1];
                    if(aux < g) {f = false; i = j = 2*n; continue;}
                    ans++;
                }
            }
            if(f) break;
        }
        printf("%d\n", ans);
}
