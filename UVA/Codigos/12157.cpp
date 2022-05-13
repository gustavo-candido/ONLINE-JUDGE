#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, n, v[30], m, j, C=0;

	cin >> N;

	while(N--) {
		cin >> n;
		m = j = 0;
		for(int i=0; i<n; i++) {
			scanf("%d", &v[i]);
			m+=(10*(v[i]/30));
			j+=(15*(v[i]/60));
			m+=10;
			j+=15;
		}
		printf("Case %d: ", ++C);
		if(m <= j) {
			printf("Mile ");
		}
		if(j <= m)printf("Juice ");	
		printf("%d\n", min(m,j));
	}
}
