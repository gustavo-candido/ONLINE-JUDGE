#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n; 
	double med, sum, tot;
	vector<double>x;
	while(scanf("%d", &n) && n) {
		sum = med = tot = 0.0;
		x.resize(n);
		for(int i=0; i<n; i++) {
			scanf("%lf", &x[i]);
			med+=x[i];
		}
		med/=n;
		for(int i=0; i<n; i++) {
			if(x[i] < med) sum+=(med-x[i]);
		}
		printf("%.2lf\n", med);
	}
}
