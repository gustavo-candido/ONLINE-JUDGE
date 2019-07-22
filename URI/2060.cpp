#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v[] = {0,0,0,0}, x;

    cin >> n;
    while(n--) {
        cin >> x;
        if(x % 2 == 0) v[0]++;
        if(x % 3 == 0) v[1]++;
        if(x % 4 == 0) v[2]++;
        if(x % 5 == 0) v[3]++;
    }
    printf("%d Multiplo(s) de %d\n", v[0], 2);
    printf("%d Multiplo(s) de %d\n", v[1], 3);
    printf("%d Multiplo(s) de %d\n", v[2], 4);
    printf("%d Multiplo(s) de %d\n", v[3], 5);
}
