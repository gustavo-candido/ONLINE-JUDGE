#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int n, d, r, mor[1000], eve[1000], tot;
	
	while(scanf("%d %d %d", &n, &d, &r) && n && d && r) {
		tot=0;
		for(int i=0; i<n; i++) scanf("%d", &mor[i]);
		for(int i=0; i<n; i++) scanf("%d", &eve[i]);
		
		sort(mor, mor+n);
		sort(eve, eve+n);
		
		for(int i=0; i<n; i++) {
			if(mor[i] + eve[n-i-1] > d) tot+=((mor[i]+eve[n-i-1]-d) * r);
		}
		printf("%d\n", tot);
	}
}
