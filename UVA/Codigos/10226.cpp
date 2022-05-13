#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, tot;
	map<string, double>mm;
	map<string, double>::iterator it;
	string A;
	cin  >>N;
	getchar();
	getchar();
	for(int c=0; c<N; c++) {
		if(c != 0) cout << endl;
		tot = 0;
		while(1) {
			getline(cin, A);
			if(A.size() == 0) break;
			if(mm.count(A)) mm[A]+=1.0;
			else mm.insert(pair<string, int> (A, 1));
			tot++;
		}
		for(it = mm.begin(); it != mm.end(); it++) {
			cout << it->first;
			printf(" %.4F\n", it->second / tot * 100);
		}
		mm.clear();
	}
}
