#include <bits/stdc++.h>
using namespace std;
long long int N, K, M, mem[66][66];

long long int bc(int n, int k) {
	if(n == 0 && k == 0) return 1LL;
	if(n <= 0 || k <= 0) return 0LL;
	if(mem[n][k] != -1LL) return mem[n][k];
	long long int ans=0LL;
	for(long long int i=1; i<=M; i++) 
		ans+=bc(n-i, k-1);
	return mem[n][k] = ans;
}
int main()
{
	while(cin >> N >> K >> M && !cin.eof()) {
		memset(mem, -1LL, sizeof mem);
		cout << bc(N, K) << endl;
	}
}
