#include <bits/stdc++.h>
#define _n 1000
#define _m 1000
using namespace std;

int main()
{
	int t, n, ans, aux, x;
	char s[_n][_m];

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		getchar();
		for(int i=0; i<n; i++) {
			gets(s[i]);
		}
		ans = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(i == j || strlen(s[i]) <= ans || strlen(s[j]) <= ans) continue;
				aux =  0;
				for(int a=0; a<strlen(s[i]); a++) {
					x=0;
					for(int b=0, k=a; b < strlen(s[j]) && k < strlen(s[i]); b++, k++) {
						if(s[i][k] == s[j][b]) x++;
						aux = max(aux, x);
					}
				}
				ans = max(ans, aux);
			}
		}
		printf("%d\n", ans);
	}

}
