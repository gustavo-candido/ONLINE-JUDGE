#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bitset<10000010>bs;
vector<ll>primes;
map<ll, ll> fp;

int get_powers(int n, int p) {
    int result = 0;
    n /= p;
    do {
        result += n;
        n /= p;
    }while(n > 0);
    return result;
}

void sieve() {
	int maxi = 1000001;
	bs.set();
	bs[0] = bs[1] = 0;
	for(ll i=2; i<=maxi; i++) {
		if(bs[i]) {
			for(ll j=i*i; j<=maxi; j+=i) {
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
} 

void fact_primes(ll x) {
	ll i=0, pf = primes[i];
	
	while(pf * pf <= x) {
		while(x % pf == 0) {
			x/=pf;
			fp[pf]++;
		}
		pf = primes[++i];
	}
	if(x != -1) fp[x]++;
	fp.erase(1);
}

int main()
{
	ll fat, divi, gp;
	bool flag;
	sieve();
	
	while(scanf("%lld %lld", &fat, &divi) != EOF) {
		flag = true;
		fp.clear();
		fact_primes(divi);
		//for(map<ll,ll>::iterator i=fp.begin(); i!=fp.end(); i++) cout << i->first << " = " << i->second << endl;
		for(map<ll,ll>::iterator i=fp.begin(); i!=fp.end(); i++) {
			gp = get_powers(fat, i->first);
			if(gp < i->second) {flag = false;break;}
		}
		if(flag) printf("%lld divides %lld!\n", divi, fat); 
		else printf("%lld does not divide %lld!\n", divi, fat);
	}
}
