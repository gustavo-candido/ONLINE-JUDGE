#include <stdio.h>
#define PI  3.14159265358979323846


double vol(double r, double h) {
	return ((r*r) * PI * h);
}

int main() {
	int w, h;
	double r, R;
	while(scanf("%d %d",&w,&h) != EOF) {
        if (w==0 && h==0) break;
        
		if (w/2.0 <= h/(PI*2+2)) r = w/2.0;
		else r =  h/(PI*2+2);
		
		R = w / (PI*2);
		
		if (vol(r, w) >= vol(R, h-2*R)) printf("%.3F\n", vol(r, w));
		else printf("%.3F\n", vol(R, h-2*R));
	}
}
