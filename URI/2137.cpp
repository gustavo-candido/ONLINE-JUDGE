#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> v;

int main(){

	while(cin >> n) {
		for(int i=0; i<n; i++) {
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end());

		for(int i=0; i<n; i++) {
			cout << v[i] << endl;
		}

		v.clear();
	}
}