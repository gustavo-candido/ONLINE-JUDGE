#include <stdio.h>

int main() 
{
	double cow, car, show, a, b;
	
	while(scanf("%lf %lf %lf", &cow, &car, &show)!= EOF) {
		a = (cow/(cow+car));
		a*=(car/(cow+car-show-1));
		b = (car/(cow+car));
		b*=((car-1)/(cow+car-show-1));
		printf("%.5lf\n", a+b);
	}
}
