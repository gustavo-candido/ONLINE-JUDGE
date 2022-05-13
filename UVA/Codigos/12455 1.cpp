#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, v[30], aux, s;
	bool f;
	scanf("%d", &t);

	while(t--) {
		f = 0;
		scanf("%d %d", &s, &n);
		for(int i=0; i<n; i++) {
			scanf("%d", v+i);
		}

		for(int bit = 0; bit < (1<<n); bit++) {
			aux = 0;
			for(int i=0; i<n; i++) {
				if(bit & (1<<i)) aux+=v[i];
			}
			if(aux == s) f = 1, bit = (1<<n);
		}
		printf("%s\n", (f)? "YES":"NO");
	}
}
