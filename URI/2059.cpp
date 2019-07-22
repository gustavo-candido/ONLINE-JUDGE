#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, j1, j2, r, a, ans;

    cin >> p >> j1 >> j2 >> r >> a;

    if(p == 1 && r == 0 && (j1+j2) % 2 == 0) ans = 1;
    else if(p == 0 && r == 0 && (j1+j2) % 2 != 0) ans = 1;
    else if(r == 1 && a == 0)ans = 1;
    else ans = 2;

    cout <<"Jogador "<< ans <<" ganha!\n";
}
