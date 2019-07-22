#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);

	int n, m;
	vector<int> a, b;
	map<int,int> pos;
	cin >> n >> m;

	a.resize(n);	
	b.resize(m);

	for(int i=0; i<n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	for(int i=0; i<m; i++) {
		cin >> b[i];
	}
	
	int ans=abs(pos[b[0]]-pos[a[0]]); 


	for(int i=1; i<m; i++) {
		ans+=abs(pos[b[i]]-pos[b[i-1]]);
	}
	cout << ans << endl;
}