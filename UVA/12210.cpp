#include <bits/stdc++.h>
using namespace std;

int main()
{
	int b, s, aux, esq, dir, C=1;
	int x[70];
	int y[70];
	
	while(scanf("%d %d", &b, &s) && b+s) {
		memset(x, 0, sizeof x);
		memset(y, 0, sizeof y);
		for(int i=0; i<b; i++) {scanf("%d", &aux);x[aux]++;}
		for(int i=0; i<s; i++) {scanf("%d", &aux);y[aux]++;}
		
		printf("Case %d: ", C++);
		if(b > s) printf("%d ", b-s);
		else {puts("0"); continue;}
		
		for(int i=0; i<s; i++) {
			for(int j=70; j<0; j--) {
				if(y[j] > 0) {
					esq = dir = j;
					int index = -1;
					while(index == -1) {
						if(dir < 70 && x[dir] > 0) index = dir;
						if(esq >= 0 && x[esq] > 0) index = esq;
						esq--; dir++;
					}
					x[index]--;
				}
			}
		}
		for(int i=0; i<70; i++) 
			if(x[i] > 0) {
				printf("%d\n", i);
				break;
			} 
	}
}
