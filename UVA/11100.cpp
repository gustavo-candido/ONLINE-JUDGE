#include <bits/stdc++.h>
using namespace std;

int main()
{
	int v[10100], n, knap, aux;
	bool line = false;
	while(scanf("%d", &n) && n) {
		if(line) puts("");
		line = 1;
		for(int i=0; i<n; i++) scanf("%d", &v[i]);
		sort(v, v+n);

		knap = aux = 1;
		for(int i=1; i<n; i++) {
			if(v[i] == v[i-1]) aux++;
			else aux = 1;
			knap = max(knap, aux);
		}

		printf("%d\n", knap);

		for(int i=0; i<knap; i++) {
			bool ft = 0;
			for(int j=i; j<n; j+=knap) {
				if(ft)printf(" ");
				ft = 1;
				printf("%d", v[j]);
			}puts("");
		}
	}
}
