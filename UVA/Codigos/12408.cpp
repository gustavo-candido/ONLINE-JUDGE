#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t, R, C, Z=1;
	bool f, no_ans;
	char box[52][52];
	scanf("%d", &t);

	while(t--) {
		no_ans=0;
		scanf("%d %d", &R, &C);
		getchar();
		for(int i=0; i<R; i++) {
			f = 0;
			for(int j=0; j<C; j++) {
				scanf("%c", &box[i][j]);
				if(box[i][j] == '0') f = 1;
			}getchar();
			if(!f) no_ans=1;
		}
		if(no_ans){
			printf("Case %d: -1\n", Z++);
			continue;
		}
		int aux, ans = 1000000000, x;
		for(int i=0; i<R; i++) {
			aux=0;
			for(int r=0; r<R; r++) { 
				x =  5000;
				for(int c=0; c<C; c++) {
					if(box[r][c] == '0' && abs(c-i) < abs(x-i)) {
						x = c;
					}
				}
				aux+=abs(x-i);
			}
			ans = min(ans, aux);
		}
		printf("Case %d: %d\n", Z++, ans);
	}
}
