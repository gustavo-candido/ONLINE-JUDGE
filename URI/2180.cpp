#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bitset<10000010>b;
void sieve(){
    b.set();

    b[0] = b[1] = 0;

    for(ll i=2; i<=10000000; i++){
        if(b[i]) {
            for(ll j = i*i; j<=10000000; j+=i) b[j] = 0;
        }
    }
}
int main()
{
    int i, p, x=0;
    double tot=0, d = 60000000.0;

    sieve();

    scanf("%d", &i);

    while(x < 10) {
        if(i > 10000000) break;
        if(b[i]) x++, tot+=(double)i;
        i++;
    }
    cout << (long long int)tot <<" km/h\n";
    cout << (long long int)(d/tot) << " h / " << ((long long int)((d/tot)/24.0)) << " d\n";
}
