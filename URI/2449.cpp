#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	v.resize(n);

	for(int i=0; i<n; i++) cin >> v[i];
	
	int ans = 0;


	for(int i=0; i<n-1; i++) {
		if(v[i] == m) continue;
		else {
			ans+=(abs(v[i]-m));
			if(v[i] < m) v[i+1]+=(abs(v[i]-m));
			else v[i+1]-=(abs(v[i]-m));
			v[i] = m;
		}
	}	
	cout << ans << endl;
}