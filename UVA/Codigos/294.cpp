#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bitset<10000010>bs;
vector<int> primes;

void sieve() {
	int maxi = 10000001;
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(ll i=2; i<=maxi; i++) {
		if(bs[i]) {
			for(ll j=i*i; j<=maxi; j+=i) bs[j]=0;
			primes.push_back((int)i);
		}
	}
}

int divi(ll x) {
	ll i=0, pf = primes[i], ans=1, power;
	
	while(pf*pf <= x) {
		power=0;
		while(x % pf == 0) {
			x/=pf;power++;
		}
		ans*=(power+1);
		pf = primes[++i];
	}
	if(x != 1) ans *= 2;
	return ans;
}

int main()
{
	ll n, l, u, maxi, n_divi, num;
	
	sieve();
	scanf("%lld", &n);
	
	while(n--) {
		maxi=0;
		scanf("%lld %lld", &l, &u);
		num = l;
		for(ll i=l; i<=u;i++) {
			n_divi = divi(i);
			//printf("%lld tem %lld divi\n", i, n_divi);
			if(maxi < n_divi) {
				maxi = n_divi;
				num = i; 
			}
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, u, num, maxi);
	}
}
