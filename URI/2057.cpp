#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a  >> b >> c;

    int soma = (a+b+c) % 24;
    if(soma < 0) soma = 24+soma;
    cout << soma << endl;
}
