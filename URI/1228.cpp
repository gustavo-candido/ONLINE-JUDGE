#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ini[55], fim[55], n, ans=0;

	while(scanf("%d", &n)!=EOF) {
		ans=0;
		for(int i=0; i<n; i++)scanf("%d", &ini[i]);
		for(int i=0; i<n; i++)scanf("%d", &fim[i]);

		for(int i=0; i<n; i++) {
			if(ini[i] != fim[i]) {
				int j;
				for(j=0; j<n; j++) {
					if(ini[i] == fim[j])break;
				}
				while(j != i) {
					ans++;
					int aux = fim[j];	
					fim[j] = fim[j-1];
					fim[j-1] = aux;
					j--;
				}
			}
		}
		printf("%d\n", ans);

	}

}