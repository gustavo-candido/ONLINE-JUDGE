#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	map<char, int> A, X;
	while(getline(cin, a) && !cin.eof()) {
		getline(cin, b);
		for(int i=0; i<(int)a.size(); i++){
			 A[a[i]]++;
		 }
		for(int i=0; i<(int)b.size(); i++) {
			if(A.count(b[i])) {
				X[b[i]]++;
				A[b[i]]--;
				if(A[b[i]] == 0) A.erase(b[i]);
			}
		}
		for(map<char, int>::iterator i=X.begin(); i != X.end(); i++)  
			while(i->second) {
				cout << i->first;
				X[i->first]--;
			}
		puts("");
		A.clear();X.clear();
	}
}
