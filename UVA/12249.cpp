#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t, n, ans, C=1;
	char s[50][50], aux[1001];

	scanf("%d", &t);

	while(t--) {
		ans = 10000000;
		scanf("%d", &n);
		getchar();
		for(int i=0; i<n; i++) {
			scanf("%s", s[i]);
		}
		int v[n];
		for(int i=0; i<n; i++) v[i] = i;
		
		do {
			strcpy(aux, s[v[0]]);
			for(int k=1; k<n; k++) {
				int cont = 0, ini = strlen(aux);
				for(int i=0; i<strlen(aux); i++) {
					int x = i, y = 0, z = 0;
					while(x < strlen(aux) && y < strlen(s[v[k]]) && aux[x] == s[v[k]][y]) x++, y++, z++;
					if(x == strlen(aux)) {
						if(z > cont) {
							cont = z;
							ini = i;
						}
					}  
				}	
				for(int i=0; i<strlen(s[v[k]]); i++) {
					aux[ini] = s[v[k]][i];
					ini++;
				}
				aux[ini] = '\0';
			}
			ans = min(ans, (int)strlen(aux));
		} while(next_permutation(v, v+n));
		
		printf("Case %d: %d\n", C++, ans);
	}
}



