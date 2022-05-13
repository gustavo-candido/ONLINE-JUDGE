#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bitset<10000010>bs;
vector<int> primes;

void sieve () {
	long long int maxi = 10000001;
	bs.set();
	bs[0]=bs[1]=0;
	
	for(ll i=2; i<=maxi; i++) {
		if(bs[i]) {
			for(ll j= i*i; j<=maxi; j+=i) {
				bs[j] = 0;
			}
			primes.push_back((int)i);
		}
	}
}

int main () {
	int n;
	bool x;
	sieve();
	while(scanf("%d", &n) && n) {
		x = false;
		for(int i = 0; i <= n/2; i++) {
			if(binary_search(primes.begin(), primes.end(), n-primes[i])) {
				printf("%d = %d + %d\n", n, primes[i], n-primes[i]);
				x = true;
				break;
			}
		}
		if(!x) printf("`Goldbach's conjecture is wrong.\n");
	}
}
