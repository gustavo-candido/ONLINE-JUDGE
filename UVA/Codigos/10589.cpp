#include <bits/stdc++.h>
using namespace std;

typedef struct point {
	double x, y;
	point(){x=y=0.0;};
	point(double _x, double _y): x(_x), y(_y) {};
}point;

bool inside(point p, point c, double r) {
	double dx = (p.x-c.x), dy = (p.y-c.y), d = dx * dx + dy * dy;
	r*=r;
	return (d <= r)? true:false; 
}
int main()
{
	long long int N, a, M;
	double x, y;
	point A, B, C, D, p;
	while(cin >> N >> a && N && a) {
		A = point(0.0,0.0);
		B = point((double)a,0.0);
		C = point((double)a,(double)a);
		D = point(0.0,(double)a);
		M = 0;
		for(int i=0; i<N; i++) {
			cin >> x >> y;
			p = point(x,y);
			if(inside(p,A, (double)a) && inside(p,B, (double)a) && inside(p,C, (double)a) && inside(p,D, (double)a)) M++;
		}
		printf("%.5lf\n", (double)M * (double)a * (double)a/(double)N);
	}
	
	
}
