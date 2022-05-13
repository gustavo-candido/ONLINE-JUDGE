#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, x, aux;
	vector<int>v;
	string op;
	cin >> t;

	while(t--) {
		v.clear();
		cin >> n;
		x = 0;
		for(int i=0; i<n; i++) {
			cin >> op;
			if(op == "LEFT") v.push_back(-1);
			else if(op == "RIGHT") v.push_back(1);
			else {
				cin >> op >> aux;
				v.push_back(v[aux-1]);
			}
			x+=v[v.size()-1];

		}
		printf("%d\n", x);
	}
}
