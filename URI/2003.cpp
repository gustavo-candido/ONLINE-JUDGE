#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m;
    while(scanf("%d:%d", &h, &m) != EOF) {
        h++;
        h*=60;
        h+=m;
        cout << "Atraso maximo: ";
        if(h > 8*60) cout << h-8*60;
        else cout << "0";
        puts("");
    }
}
