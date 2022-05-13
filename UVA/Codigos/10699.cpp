#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bitset<10000010>bs;
vector<ll> prime;

void sieve () {
	int maxi = 10000001;
	 bs.set();
	 bs[0] = bs[1] = 0;
	 
	 for(ll i=0; i<=maxi; i++) {
		 if(bs[i]) {
			 for(ll j= i*i; j<=maxi; j+=i) {
				 bs[j] = 0;
			 } 
			 prime.push_back(i);
		 }
	 }
}
int fat_prime(ll x) {
	ll i=0, pf = prime[i], ans=0;
	
	while(pf * pf <= x) {
        if(x % pf == 0)ans++;
		while(x % pf == 0) {
			x/=pf;		
		}
		pf = prime[++i];
	}
	if(x != 1) ans++;
	return ans;
}

int main ()
{
	int n;
	sieve();
	while(scanf("%d", &n) && n) {
		printf("%d : %d\n", n, fat_prime(n));
	}
}
