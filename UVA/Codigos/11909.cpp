#include<bits/stdc++.h>
#define pi acos(-1)
using namespace std;


double vol(int l, int w, int h, int theta) {
	double radius = pi/180.0*theta;
	double c1, c2, hp;
	
	c1 = sin(pi - (radius+pi/2)) * h;
	c2 = sin(radius) * l;
	
	if(c1 > c2) {
		hp = tan(radius) * l;
		return (l * h * w) - (0.5 * hp * l * w);
	}
	else{
		radius = pi - (radius + (pi/2));
		hp = h * tan(radius);
		return (0.5 * h * hp * w);
	}
}

int main()
{
	int l, h, w, theta;
	
	while(cin >> l >> w >> h >> theta) {
		
		printf("%.3lf mL\n", (double)vol(l,w,h,theta));
	}
}
