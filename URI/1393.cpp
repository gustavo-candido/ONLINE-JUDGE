#include <bits/stdc++.h>
using namespace std;

int main()
{
    int fib[50];
    int x;
    fib[1] = 1;
    fib[2] = 2;

    for(int i=3; i<=41; i++) {
        fib[i] = fib[i-1]+fib[i-2];
    }
    while(cin >> x && x) {
        cout << fib[x] << endl;
    }
}
