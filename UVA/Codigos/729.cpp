#include <bits/stdc++.h>
using namespace std;

string a;
int n, h;

void f(int id, int bits) {
    if(bits == h) {
        cout << a << "\n";
        return;
    }
    if(id < 0 || a[id] == '1') return;
    a[id] = '1';
    f(n-1, bits+1);
    a[id] = '0';
    f(id-1, bits);
}
int main()
{
        int t;

        scanf("%d", &t);

        for(int i=0; i<t; i++) {
            if(i)puts("");
            scanf("%d %d", &n, &h);
            a.assign(n, '0');
            f(n-1, 0);
        }
}

