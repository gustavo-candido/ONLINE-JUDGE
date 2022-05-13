#include <bits/stdc++.h>
using namespace std;

main ()
{
	int n, x;
	bool f;
	
	while(scanf("%d", &n) && n) {
		f = true;
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			if(x > 0) {
				if(f){ printf("%d", x);f=false;}
				else printf(" %d", x);
			}
		}
		if(f) printf("0\n");
		else printf("\n");
	}
}
