#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n, a;
	vector<long long int> v;
	
	while(cin >> n && n) {
		v.clear();
		while(n--)  {
			cin >> a;
			v.push_back(a);
		}
		a = abs(v[0]);
		for(int i=1; i<(int)v.size(); i++){
			v[i]+=v[i-1];
			a+=abs(v[i]);
		}
		cout << a << endl;
	}
}
