#include <bits/stdc++.h>
using namespace std;

vector <int> p, rnk;

void inicia (vector<int> p, vector<int> rnk, int N) {
	p.assign(N, 0);
	rnk.assign(N, 0);
	for(int i=0; i<N; i++) p[i] = i;
}

int find(int i) {
	return (p[i] == i) ? i : p[i] = find(p[i]);
}

bool mesma(int i, int j) {
	return (find(i) == find(j)) ?  true : false;
}

void uni (int i, int j) {
	if (!mesma(i, j)) {
		int x, y;
		x = find(i);
		y = find(j);
		if(rnk[x] > rnk[y]) p[y] = x;
		else {
			p[x] = y;
			if(rnk[x] == rnk[y]) rnk[y]++;
		}
	}
}
