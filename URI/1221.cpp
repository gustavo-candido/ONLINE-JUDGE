#include <bits/stdc++.h>
using namespace std;

bitset<10000010>b;
typedef long long int ll;
vector<ll>primo;
map<ll, bool> m;
void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for(ll i=2; i<=10000000; i++) {
        if(b[i]) {
            for(ll j=i*i; j<=10000000; j+=i) {
                b[j] = 0;
            }
            primo.push_back(i);
        }
    }
}

bool e_primo(ll x) {
    if(m.count(x)) return m[x];

    for(int i=0; i<primo.size(); i++) {
        if(x % primo[i] == 0 && x != primo[i])return m[x] = false;
    }
    primo.push_back(x);
    return m[x] = true;
}
int main()
{
    sieve();
    ll x;
    int t;

    scanf("%d", &t);

    while(t--) {
        scanf("%lld", &x);
        if(!e_primo(x)) printf("Not ");
        printf("Prime\n");
    }
}
