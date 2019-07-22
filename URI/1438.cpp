#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n, p;
	int x, y, tam[1003], aux;

	while(scanf("%d %d", &n, &p) && n+p != 0) {

		for(int i=0; i<p; i++) {
			scanf("%d", &tam[i]);
			for(int j=0; j<tam[i]; j++) {
				scanf("%d", &aux);
				if(aux == 1) {
					x = i; 
					y = j;
				}
			}
		}

		int esq=0, dir=0;

		for(int i=x-1; i>=0; i--) {
			if(tam[i] <= y) break;
			esq+=tam[i]-y;
		}

		for(int i=x+1; i<p; i++) {
			if(tam[i] <= y) break;
			dir+=tam[i]-y;
		}

		cout <<  min(esq,dir) + tam[x] - y - 1 << endl;
	}

	return 0;
}