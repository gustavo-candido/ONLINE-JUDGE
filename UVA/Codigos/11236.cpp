#include <bits/stdc++.h>
using namespace std;

bool valid(double a, double b, double c, double d) {
	double aa = (a+b+c+d);
	double bb = (a*b*c*d);
	if (aa == bb && bb <= 20.0) return true;
	else return false;
}
int main()
{
	int p1, p2, p3, p4, a, b, c, d, e;

	for(int p1 = 1; p1 <=2000; p1++) {
		if(p1*p1*p1*p1 > 2000000000) continue;
		for(int p2 = p1; p2 <=2000-p1; p2++) {
			if(p1*p2*p2*p2 > 2000000000) continue;
			for(int p3 = p2; p3 <=2000-p2-p1; p3++) {
				if(p1*p2*p3*p3 > 2000000000) continue;
				
				a = p1+p2+p3;
				b = p1*p2*p3;
				c = 1000000;
				if(b == c) continue;
				if((c*a)%(b-c) != 0) continue;
				p4 = (c*a)/(b-c);
				
				if(p3 > p4) continue;
				if(a+p4 > 2000) continue;
				if(b*p4 > 2000000000)continue;
				if((p1+p2+p3+p4)*1000000 == p1*p2*p3*p4) printf("%.2lf %.2lf %.2lf %.2lf\n", (double)p1/100.0, (double)p2/100.0, (double)p3/100.0, (double)p4/100.0);
			}
		}
	}
}
