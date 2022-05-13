#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, n, v[60], up, down, C=0;
	
	cin >> N;
	while(N--) {
		printf("Case %d: ", ++C);
		up =  down = 0;
		cin >> n;
		for(int i = 0; i < n; i++) scanf("%d", &v[i]);
		if(n == 1) puts("0 0");
		else {
			for(int i = 0; i < n-1; i++) {
				if(v[i]- v[i+1] > 0) up++;
				else if (v[i]- v[i+1] < 0) down++; 
			}
			printf("%d %d\n", down, up);
		}
	}
}
