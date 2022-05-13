#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t, n , c;
	vector<int>a, b;

	cin >> t;

	while(t--) {
		cin >> n;
		a.resize(n);
		b.resize(n);
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		c=0;
		for(int i=1; i<n; i++) {
			b[i]=0;
			for(int j=0; j<i; j++) {
				if(a[i] >= a[j]) b[i]++; 			
			}
			c+=b[i];
		}
		cout << c << endl;
	}
}
