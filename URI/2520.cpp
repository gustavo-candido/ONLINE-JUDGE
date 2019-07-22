#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
int main()
{
    int n, m, x;
    ii a, b;

    while(scanf("%d %d", &n, &m) != EOF){
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                scanf("%d", &x);
                if(x == 1){
                    a = ii(i,j);
                }
                if(x == 2) {
                    b = ii(i,j);
                }
             }
        }

        printf("%d\n", abs(a.first - b.first) + abs(a.second - b.second));
    }
}
