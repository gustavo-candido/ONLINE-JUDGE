#include <bits/stdc++.h>
using namespace std;

void anagram (string A, map<string, string> &mm) {
	string B;
	for(int i=0; i< A.size(); i++) {
		if(A[i] != ' ') B.push_back(A[i]);
	}
	sort(B.begin(), B.end());
	mm[A] = B;
} 
main ()
{
	int N;
	map<string, string> mm;
	vector<string>list;
	string A;
	cin >> N;
	getchar();
	getchar();
	for(int c=0; c<N; c++) {
		if(c > 0) cout << endl;
		while(1) {
			getline(cin, A);
			if(A.size() == 0)break;
			anagram(A, mm);
			list.push_back(A);
		}
		sort(list.begin(), list.end());
		for(int i=0; i<list.size(); i++) {
			for(int j=i+1; j<list.size(); j++) {
				if(mm[list[i]] == mm[list[j]]) cout << list[i] << " = " << list[j] << endl;
			}
		}
		list.clear();
		mm.clear();
	}
}
