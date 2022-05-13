#include <bits/stdc++.h>
using namespace std;
int main ()
{
	int n, C=1;
	int aux[] = {0,1,2,3,4,5,6,7,8,9,10}, pach[10];
	set<double> xx;
	double x, ans;
	vector< pair<int, int> > v;
	while(scanf("%d", &n), n) {
		v.resize(n);
		ans = 200000000;
		for(int i=0; i<n; i++) scanf("%d %d", &v[i].first, &v[i].second);	
		sort(aux, aux+11);
		do {
			x = 0.0;
			for(int i=0; i<n-1; i++)
				x+=sqrt( pow(v[aux[i]].first-v[aux[i+1]].first,2) + pow(v[aux[i]].second-v[aux[i+1]].second,2))+16.0;
			
			xx.insert(x);
			if(x < ans) {
				ans = x;
				copy(aux, aux+n, pach); 
			}
			
		}while(next_permutation(aux, aux+n));
		printf("**********************************************************\nNetwork #%d\n", C);
		for(int i=0; i<n-1; i++) {
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2F feet.\n", v[pach[i]].first, v[pach[i]].second, v[pach[i+1]].first, v[pach[i+1]].second, sqrt( pow(v[pach[i]].first-v[pach[i+1]].first,2) + pow(v[pach[i]].second-v[pach[i+1]].second,2)) + 16.0);
		}
		printf("Number of feet of cable required is %.2F.\n", ans);
		C++;
	}
}
