#include <bits/stdc++.h>
using namespace std;

bitset<100>p;
int v[21];
bool used[21];
void sieve()
{
	p[0] = 0;
	int div;
	for(int i=1; i<100; i++) {
		div = 0;
		p[i] = 0;
		for(int j=1; j<=i; j++) {
			if(i % j == 0) div++;
		}
		if(div == 2) p[i] = 1;
	}
}
int n;

void back(int id, int bit) {
	if(id == n) {
		if(p[(v[n-1]+v[0])]) {
			cout << v[0];
			for(int i=1; i<n; i++) cout << " " << v[i];
			puts("");
		}
		return;
	}
	for(int i=1; i<=n; i++) {
		if(!(bit & (1<<i)) && p[i+v[id-1]]){
			v[id] = i;
			back(id+1, bit|(1<<i));
		}
	}
	
}

int main()
{	
	int c=0;
	sieve();
	while(cin >> n && !cin.eof()) {
		if(c) puts("");
		cout << "Case " << ++c << ":\n";
		v[0] = 1; 
		back(1, 3);
	}
}
