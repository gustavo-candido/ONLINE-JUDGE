#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	vector<int> v;
	
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		v.resize(x);
		for(int j=0; j<x; j++) {
			scanf("%d", &v[j]);
		}
		printf("Case %d: %d\n", i+1, v[x/2]);
	}
}
