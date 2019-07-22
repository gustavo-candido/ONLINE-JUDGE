#include <bits/stdc++.h>
using namespace std;

int main()
{
    string b;
    int bits=0;
    getline(cin, b);
    for(int i=0; i<b.size(); i++) if(b[i] == '1') bits++;
    if(bits % 2 == 0) b.push_back('0');
    else b.push_back('1');
    cout << b << endl;
}
