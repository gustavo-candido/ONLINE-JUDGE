#include <bits/stdc++.h>
using namespace std;

inline bool prime(int n) {
    int r = sqrt(n);
    for(int i=2; i<=r; i++) {
        if(n%i == 0) return 0;
    }
    return 1;
}

int main()
{
    int n;

    cin >> n;

    do{
            if(prime(n)) break;
    }while(n--);

    cout << n << endl;
}
