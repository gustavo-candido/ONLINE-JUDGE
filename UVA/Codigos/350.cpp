/**
 * aceppted
 * #include <bits/stdc++.h>
using namespace std;

int main (){
	int Z, I, M, L, c=1;
	set<int> s;
	
	while(scanf("%d %d %d %d", &Z, &I, &M, &L) && Z && I && M && L) {
		s.clear();
		while(1) {
			L = (Z*L+I) % M;
			if(s.count(L)) break;
			s.insert(L);
		}
		printf("Case %d: %d\n", c,(int)s.size());
		c++;
	}
}
**/

#include <bits/stdc++.h>
using namespace std;

int Z,I,M;
int f(int L) {return ((Z*L+I)%M);}

pair<int,int> floyd_cicle(int x0) {
	int mu, tam, tortoise, hare;
	tortoise = f(x0);
	hare = f(f(x0));
	
	while(tortoise != hare) {
		tortoise = f(tortoise);
		hare = f(f(hare));
	}
	mu=0; hare = x0;
	
	while(tortoise != hare) {
		tortoise = f(tortoise);
		hare = f(hare);
		mu++;
	}
	tam = 1; hare = f(tortoise);
	
	while(tortoise != hare) {
		hare = f(hare);
		tam++;
	}
	return pair<int,int>(mu,tam);
}

int main()
{
	int L;
	int c=1;
	pair<int,int>ans;
	while(scanf("%d %d %d %d", &Z, &I, &M, &L) && Z && I && M && L) {
		ans = floyd_cicle(Z);
		printf("Case %d: %d\n", c, ans.second);
		c++;
	}
}
