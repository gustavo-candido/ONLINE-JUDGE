#include <bits/stdc++.h>
#define EPS 0.0001
#define INF 1e9
#define _n 10005
using namespace std;

int main()
{
	int n, a, v[_n], mini, maxi, aux;
	double tot;
	while(scanf("%d %d", &n, &a) && n+a) {
		memset(v, 0, sizeof v);
		mini = INF;
		maxi = -INF;
		tot = 0;
		for(int i=0; i<n; i++){ ///O(n)
			scanf("%d", &aux);
			v[aux]++;
			tot+=aux;
			mini = min(mini, aux);
			maxi = max(maxi, aux);
		}
		maxi = min(maxi, 10000);
		mini = max(mini, 0);
		if(tot < a) puts("-.-");
		else if (tot == a) puts(":D");
		else {
			double l=0, r=maxi, m, sum;
			while(l <= r) { ///O(logn)
				m =(l+r)/2.0;
				sum = 0;
				for(int i=maxi; i >=mini; i--) { ///O(n)
					if(i - m < 0) break;
					sum+=((i-m)*v[i]);
				}	
				if(fabs(sum - a) < EPS) break;
				if(sum - a < 0) r = m;
				else if(sum - a > 0) l = m;
		
			}
			printf("%.4lf\n", m);
		}
	}
}