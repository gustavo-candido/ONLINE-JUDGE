#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int a, b, c;
	double R;
	while(scanf("%d %d %d", &a, &b, &c)) {
		if(!a && !b && !c) break;
		R = (a - 7)*(b - 7)/2.0;
		if(c == 1) R = ceil(R); 
		printf("%d\n",(int)R);
		
	}
}
