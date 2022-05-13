#include <bits/stdc++.h>

using namespace std;

typedef pair<long long int,long long int> ii;
typedef pair<ii, long long int> iii;

int main()
{
	int N;
	set<iii> comb, perm;
	while(scanf("%d", &N) && N > 0) {
		comb.clear();
		perm.clear();
		for(int i=0; i<=21; i++) {
			if(i == 21) i=50;
			if(i > N) break;
			for(int j=0; j<=21; j++) {
				if(j == 21) j=50;
				if(i+j > N) break;
				for(int k=0; k<=21; k++) {
					if(k == 21) k=50;
					if(i+j+k > N) break;
					for(int a=1; a<4; a++) {
						for(int b=1; b<4; b++) {
							for(int c=1; c<4; c++) {
								int m, n, o;
								m = (i!=50)?a:1;
								n = (j!=50)?b:1;
								o = (k!=50)?c:1;
								if(i*m+j*n+k*o == N){
									perm.insert(iii(ii(i*m, j*n), k*o));
									int r[3] = {i*m, j*n, k*o};
									sort(r, r+3);
									comb.insert(iii(ii(r[0], r[1]), r[2]));
								}
							}
						}
					}
				} 
			}
		}
		if(comb.empty())printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
		else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %lld.\n", N, comb.size());
			printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %lld.\n", N, perm.size());
		}
		puts("**********************************************************************");
	}
	puts("END OF OUTPUT");
}
