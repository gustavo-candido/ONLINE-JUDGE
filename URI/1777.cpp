#include <bits/stdc++.h>
using namespace std;

struct cam{
	int a, b;
	cam() {a = b = 0;}
	cam(int _a, int _b): a(_a), b(_b) {}

	bool operator < (cam other) const {
		return a < other.a;
	}
};
int main()
{
	int T, N , C, ans, a;
	vector<cam> c;
	map<int,int> m;
	
	scanf("%d", &T);
	for(int t=1; t<=T; t++) {
		m.clear();
		ans=0;
		scanf("%d %d", &N, &C);
		c.resize(C);
		for(int i=0; i<C; i++) {
			scanf("%d %d", &c[i].a, &c[i].b);
		}
		sort(c.begin(), c.end());
		for(int i=0; i<C; i++) {
			if(m.count(c[i].a)){
				if(c[i].b > m[c[i].a])m[c[i].a] = c[i].b;
			} 
			else m[c[i].a] = c[i].b;
		}
		scanf("%d", &N);
		while(N--) {
			scanf("%d", &a);
			for(map<int,int>::iterator i = m.begin(); i != m.end(); i++) {
				if(i->first <= a && a <= i->second) {ans++;break;}
				else if(i->first > a) break;
			}
		}
		printf("Caso #%d: %d\n", t, ans);
	}
	
}	