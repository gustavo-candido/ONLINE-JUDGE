#include <bits/stdc++.h>
using namespace std;

int main ()
{
	vector<string> mk;
	vector<long long int> min, max;
	long long int N, n, Q, q;
	string A;
	
	cin >> N;
	
	for(int C=0; C < N; C++) {
		if(C != 0) cout << endl;
		cin >> n;
		mk.resize(n);
		min.resize(n);
		max.resize(n);
		for(int i=0; i<n; i++) {
			cin >> mk[i] >> min[i] >> max[i];
		}
		cin >> Q;
		while(Q--) {
			cin >> q;
			A = "xoxo";
			for(int i=0; i<n; i++) {
				if(q >= min[i] && q <= max[i]) {
					if (A == "xoxo") {
						A = mk[i];
					}
					else {A = "UNDETERMINED";break;}
				}
			}
			if(A == "xoxo") {
				cout << "UNDETERMINED\n";
			}
			else cout << A << endl;
		}
	}
}
