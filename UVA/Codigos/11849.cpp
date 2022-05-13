#include <bits/stdc++.h>
using namespace std;

int main ()
{
	set<int>s;
	int N, M, aux, count;
	
	while(cin >> N >> M) {
		if(!N && !M) break;
		s.clear();
		count=0;
		while(N--) {
			cin >> aux;
			s.insert(aux);
		}
		while(M--) {
			cin >> aux;
			if(s.count(aux))count++;
		}
		cout << count << endl;
	}
}
