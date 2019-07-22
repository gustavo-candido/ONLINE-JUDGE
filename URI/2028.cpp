#include <bits/stdc++.h>
using namespace std;

int main()
{
    int C=1, n;
    while(cin >> n && !cin.eof()) {
        if(n == 0) printf("Caso %d: 1 numero\n0\n", C++);
        else {
            printf("Caso %d: %d numeros\n0", C++, ((n * (1 + n))/2)+1 );
            for(int i=1; i<=n; i++) {
                for(int j=0; j<i; j++) {
                    printf(" %d", i);
                }
            }puts("");
        }puts("");
    }
}
