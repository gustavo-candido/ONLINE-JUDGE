#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, v[10005];
	bool f;
	set<int> s;
	while(scanf("%d:", &n)  && n) {
		s.clear();
		f = 1;
		for(int i=0; i<n; i++) {
			scanf("%d", &v[i]);
			s.insert(v[i]);
		}
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++){
				if(s.count(2*v[i]-v[j])){
					f = 0; 
					i = j = 1000000;
				}
			}
		}
		
		if(f) puts("yes");
		else puts("no");
	}
}
