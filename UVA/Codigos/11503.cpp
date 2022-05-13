#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int N, ed, maxi;
	string dest, ori;
	map <string, set<string> > mm;
	cin >> N;
	
	while(N--) {
		mm.clear();
		cin >> ed;
		getchar();
		maxi = 0;
		while(ed--) {
			cin >> ori;
			if(!mm[ori].count(ori)) {
				mm[ori].insert(ori);
			}
			cin >> dest;
			if(!mm[ori].count(dest)) {
				mm[ori].insert(dest);
			}
		}
		for(map<string, set<string> >::iterator i = mm.begin(); i != mm.end(); i++) {
			string x = i->second;
			cout << x << endl;
		}
	}
}
