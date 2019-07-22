#include <bits/stdc++.h>
#define pi acos(-1) 

#define form(x, r, R, H) ( (pi * x * ((r*r)+(r* ( R*H-((R-r) *(H-x))))/H + (( R*H-((R-r) *(H-x)))*( R*H-((R-r) *(H-x))))/(H*H))))
using namespace std;

int C, N, L;
int b, B, H;
double V;

int search() {
	double l = 0.0, r = H, x, mid;
	bool f=false;
	while(l < r && !f) {
		mid = (l+r)/2;
		x = form(mid, b, B, H);
		if(fabs(x - (3.0*V)) < 0.0000001) f =true;
		else if(x < (3.0*V) ) l = mid;
		else r = mid;
	}
	printf("%.2lf\n", mid);
}
int main()
{
	
	
	scanf("%d", &C);
	
	while(C--) {
		scanf("%d %d", &N, &L);
		V = (double) L/ (double) N;
		scanf("%d %d %d", &b, &B, &H);
		search();
	}
}