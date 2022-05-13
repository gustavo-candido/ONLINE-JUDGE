#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
	int v[1005], n, t;

	cin >> t;

	while(t--) {
		scanf("%d", &n);
		for(int i=0; i<n; i++) scanf("%d", &v[i]);
		ll aux = v[0];
		int ans = 1; 
		for(int i=1; i<n-1; i++) {
			if(aux+v[i] < v[i+1]) {
				ans++;
				aux+=v[i];
			}
		}
		printf("%d\n", ans+1);
	}
}
