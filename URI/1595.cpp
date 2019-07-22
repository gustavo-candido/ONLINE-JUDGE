#include <bits/stdc++.h>
using namespace std;

int main()
{
    int C, n, m, add, vet[100005], count[205], maxi = 202;

    scanf("%d", &C);

    while(C--) {
        scanf("%d %d %d", &n, &m, &add);

        for(int i=0; i<=maxi; i++) count[i] = 0;

        for(int i=0; i<n; i++){
            scanf("%d", &vet[i]);
            count[vet[i]]++;
        }

        int sz=0;

        for(int i=0; i<=maxi; i++)
            while(count[i]){
                vet[sz++] = i;
                count[i]--;
            }

        double ans=0.0;
        for(int i=0; i<m; i++) ans+=(1.0/(double)(vet[i]+add));
        for(int i=m; i<n; i++) ans+=(1.0/(double)vet[i]);

        printf("%.2lf\n", ans);
    }
}
