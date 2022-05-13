#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;


int main()
{
	int area[5][5], t, n, r, c, w, A, B, C, D, E;

	scanf("%d", &t);

	while(t--) {
		scanf("%d", &n);
		memset(area, 0, sizeof(area));
		while(n--) {
			scanf("%d %d %d", &r, &c, &w);
			area[r][c] = w;
		}
		int x, y;
		ll aux, ans = 1e14, sum;
		for(int a=0; a<21; a++) {
			for(int b=1; b<22; b++) {
				if(!(a < b)) continue;
				for(int c=2; c<23; c++) {
					if(!(b < c)) continue;
					for(int d=3; d<24; d++) {
						if(!(c < d)) continue;
						for(int e=4; e<25; e++) {
							if(!(d < e)) continue;
							sum = 0;
							for(int i=0; i<5; i++) {
								
								for(int j=0; j<5; j++) {
									aux=1e14;
									x = a/5;
									y = a%5;
									aux = min(aux, (ll)(abs(x-i) + abs(y-j))*area[i][j]);
									x = b/5;
									y = b%5;
									aux = min(aux, (ll)(abs(x-i) + abs(y-j))*area[i][j]);
									x = c/5;
									y = c%5;
									aux = min(aux, (ll)(abs(x-i) + abs(y-j))*area[i][j]);
									x = d/5;
									y = d%5;
									aux = min(aux, (ll)(abs(x-i) + abs(y-j))*area[i][j]);
									x = e/5;
									y = e%5;
									aux = min(aux, (ll)(abs(x-i) + abs(y-j))*area[i][j]);
									sum+=aux;
								}
							}
							if(sum < ans) {
								ans = sum;
								A = a;
								B = b;
								C = c;
								D = d;
								E = e;
							}
						}
					}
				}
			}
		}
		printf("%d %d %d %d %d\n", A, B, C, D, E);
	}
}
