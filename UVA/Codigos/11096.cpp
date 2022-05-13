#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef struct point {
	double x, y;
	
	point() {x = y = 0.0;}
	point(double _x, double _y): x(_x), y(_y) {};
	
	bool operator < (point other) {
		if(fabs(x - other.x) > EPS) return x < other.x;
		return y < other.y;
	}
	bool operator == (point other) {
		return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
	}
}point;

double dist (point a, point b) {
	return hypot(a.x - b.x, a.y - b.y);
}
typedef struct vec {
	double x, y;
	
	vec() {x = y = 0.0;}
	vec(double _x, double _y): x(_x), y(_y) {};
}vec;

vec toVec (point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

double cross (vec a, vec b) {
	return (a.x * b.y - a.y * b.x);
}

bool ccw(point a, point b, point c) {
	vec ab = toVec(a,b), ac = toVec(a,c);
	return cross(ab, ac) > 0;
}

bool colinear(point a, point b, point c) {
	vec ab = toVec(a,b), ac = toVec(a,c);
	return fabs(cross(ab,ac)) < EPS;
}


double CH(vector<point> P){
	vector<point>up(P.size(), point()), dn(P.size(), point());
	sort(P.begin(), P.end());
	int i=0,j=0;
	for(int k=0; k<(int)P.size(); k++) {
		while(i > 1 && ccw(up[i - 2], up[i - 1], P[k])) i--;
		while(j > 1 && !ccw(dn[j - 2], dn[j - 1], P[k])) j--;
		
		up[i++] = P[k];
		dn[j++] = P[k];
	}
	int n;
	up.resize(i);
	dn.resize(j);
	
	
	n = up.size();
	for(i=n-2; i>=1;i--) dn.push_back(up[i]); 
	dn.push_back(dn[0]);
	double p = 0.0;
	n = dn.size();
	
	for(i=1; i<n; i++) p+=dist(dn[i-1], dn[i]);
	return p;
}


int main()
{
	int N, x, y, n, len;
	vector<point> P;
	cin >> N;
	while(N--) {
		P.clear();
		cin >> len >> n;
		while(n--) {cin >> x >> y; P.push_back(point(x,y));}
		printf("%.5lf\n", max((double)len, CH(P)));
	}
}
