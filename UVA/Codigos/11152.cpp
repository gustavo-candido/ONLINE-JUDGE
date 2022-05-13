#include <bits/stdc++.h>
#define pi acos(-1)
using namespace std;

double area_tri (int a, int b, int c) {
	double s = (a+b+c)*0.5;
	return sqrt(s * (s-a) * (s-b) * (s-c));
}

double area_circ(double r) {
	return (pi * r*r);
}

double raio_circ_circ(int a, int b, int c) {
	double at = area_tri(a,b,c);
	return a * b * c / (4 * at);
}

double raio_circ_insc(int a, int b, int c) {
	double s = (a+b+c)*0.5;
	double at = area_tri(a,b,c);
	return at/s;
}

double area_circ_circ(int a, int b, int c) {
	double r = raio_circ_circ(a,b,c);
	return area_circ(r) - area_tri(a,b,c);
}

double area_circ_insc(int a,int b,int c) {
	double r = raio_circ_insc(a,b,c);
	return area_circ(r);
}

int main()
{
	int a, b, c;
	double roses, sunf, violets;
	
	while(cin >> a >> b >> c && !cin.eof()) {
		sunf = area_circ_circ(a,b,c);
		roses = area_circ_insc(a,b,c);
		violets = area_tri(a,b,c) - roses;
		printf("%.4lf %.4lf %.4lf\n", sunf, violets, roses);
	}
}
