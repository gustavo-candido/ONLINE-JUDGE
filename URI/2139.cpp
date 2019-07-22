#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, m, ans;
    int mes[] = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while(cin >> m >> d ) {
        ans=0;
        if(m == 12 && d > 25) puts("Ja passou!");
        else if(m == 12 && d == 24) puts("E vespera de natal!");
        else if(m == 12 && d == 25)puts("E natal!");
        else {
            for(int i=m; i<=12; i++) {
               if(i == m) for(int j=d; j<=mes[i]; j++){
                     if(i == 12 && j == 25)break;
                     ans++;
               }
               else for(int j=1; j<=mes[i]; j++){
                    if(i == 12 && j == 25)break;
                    ans++;
               }

            }
            printf("Faltam %d dias para o natal!\n", ans);
        }
    }
}
