
#include <bits/stdc++.h>
using namespace std;

int n, i, j, v[1000010], aux, cont, C=0;
int main()
{
    string s;
    while(cin >> s && !cin.eof()) {
        printf("Case %d:\n", ++C);
        cont = 0;
        aux = s[0];
        for(int c=0; c<(int)s.size(); c++) {
            if(aux != s[c]) cont++, aux = s[c];
            v[c] = cont;
        }
        cin >> n;
        while(n--) {
            cin >> i >> j;
            if(v[i] == v[j]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
