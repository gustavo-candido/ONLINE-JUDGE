#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, l, r, v[N];

int main()
{
    while(scanf("%d", &n) != EOF) {
        memset(v, 0, sizeof v);

        while(n--) {
            scanf("%d %d", &l, &r);
            v[l]++;
            v[r+1]--;
        }

        int k;

        scanf("%d", &k);

        for(int i=1; i<=k; i++) {
            v[i]+=v[i-1];
        }

        if(v[k] == 0) printf("%d not found\n", k);
        else {
            for(int i=1; i<=k; i++) {
                v[i]+=v[i-1];
            }
            printf("%d found from %d to %d\n", k, v[k-1], v[k]-1);
        }
    }
}