#include <bits/stdc++.h>
using namespace std;

int main()
{       
    int n, c, v[200005], ans=0, sum=0, aux, ini, maxi;

    scanf("%d %d", &n, &c);

    for(int i=0; i<n; i++) scanf("%d", &v[i]);

    ini = maxi = v[0];
    for(int i=0; i<n; i++) {
       if(v[i] <= ini) {
            ans+=sum;
            sum=0;
            ini = maxi = v[i];
            continue;
        }

        aux = v[i] - ini - c;
        if(aux > sum) sum = aux;
        else if(maxi - v[i] >= c) { // começar novo corte
            ans+=sum;
            sum=0;
            ini = maxi = v[i];
        }
        maxi = max(maxi, v[i]);
    }
    if(sum) ans+=sum;
    printf("%d\n", ans);
}