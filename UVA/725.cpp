#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, aux;
	bool x, line = false;

	while(scanf("%d", &n) && n) {
		x = false;
		if(line)puts("");
		for(int b = 1234; b <= 98765; b++) {
			int a = n*b;
			if(a > 98765) break;
			int k = a;
			aux = (b < 10000);
			while(k) {aux|=1<<(k%10);k/=10;}
			k = b;
			while(k) {aux|=1<<(k%10);k/=10;}
			if(aux == (1<<10)-1)printf("%.5d / %.5d = %d\n", a, b, n), x=1;
		}
		if(!x) printf("There are no solutions for %d.\n", n);
		line = 1;
	}
}
