#include<bits/stdc++.h>
using namespace std;


int main()
{
    int ans = 0, t, x, y;

    cin >> t;

    cin >> x;

    for(int i=2; i<=t; i++) {
        cin >> y;
        if(!ans && x > y) ans = i;
        x = y;
    }
    printf("%d\n", ans);
}
