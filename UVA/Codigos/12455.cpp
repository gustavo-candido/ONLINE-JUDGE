#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int t, n, p, aux;
	vector<int> set;
	cin >> t;
	
	for(int c=0; c<t; c++) {
		cin >> n >> p;
		set.assign(n+1, 0);
		set[0]=1;
		for(int i=0; i<p; i++) {
			cin >> aux;
			for(int j=n; j>=aux; j--) {
				if(set[j-aux]) set[j] = 1;
				
			}
		}
		if(set[n]) cout << "YES\n";
		else cout << "NO\n";
	}
}
