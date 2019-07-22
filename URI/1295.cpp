#include <bits/stdc++.h>
#define INF 10000
using namespace std;
typedef struct point{
	double x, y;
	point() {x = y = 0.0;}
	point(double a, double b): x(a), y(b) {}

	bool operator < (point a) const {
		if(a.y != y) return y < a.y;
		return x < a.x;
	}
}point;

bool cmp(point a, point b) {
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

inline double dist(point a, point b) {
	return hypot(a.x-b.x, a.y-b.y);
}

int N;
vector<point>p;
set<point>l;

int main()
{
	while(scanf("%d", &N) && N) {
		p.clear();
		l.clear();
		p.resize(N);

		for(int i=0; i<N; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
		sort(p.begin(), p.end(), cmp);

		double d  = INF;
		l.insert(p[0]);

		for(int i = 1; i<N; i++) {
			for(set<point>::iterator it = l.begin(); it != l.end(); it++) {
				point j = *it;
				if(fabs(p[i].x - j.x) >= d) l.erase(j);
			}
			for(set<point>::iterator it = l.lower_bound(point(p[i].x,p[i].y-d));  it != l.end(); it++) {
				point j = *it;
				if(fabs(p[i].y - j.y) <= d) d = min(d, dist(j, p[i]));
				else break;
			}l.insert(p[i]);
		}	
		if(d == INF) puts("INFINITY");
		else printf("%.4lf\n", d);
	}
}