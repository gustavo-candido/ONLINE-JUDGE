#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, c;

    while(cin >> T && T != 0) {
        while(T--) {
            cin >> c;
           if(c % 2 != 0) cout << c*2-1 << endl;
           else cout << c*2-2 << endl;
        }
    }
}
