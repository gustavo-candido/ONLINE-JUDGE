#include <bits/stdc++.h>
typedef unsigned long long int llu;
using namespace std;

llu N, a, b;

llu f(llu x) { return (((((a*x)%N)*x)%N)+b)%N; }

pair<llu,llu> floyd_cicle(llu x0) {
	llu mu, tam, tortoise, hare;
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
	return pair<llu,llu>(mu,tam);
}

int main()
{
	pair<llu,llu>ans;
	while(scanf("%llu", &N) && N) {
		scanf("%llu %llu", &a, &b);
		ans = floyd_cicle(0);
		printf("%llu\n", N-ans.second);
	} 
}
