#include<bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main()
{
    int n, m, v[102], x;

    while(scanf("%d %d", &n, &m) != EOF){
        for(int i=0; i<n; i++) scanf("%d", &v[i]);

        sort(v, v+n, cmp);

        while(m--) {
            scanf("%d", &x);
            printf("%d\n", v[x-1]);
        }
    }
}
