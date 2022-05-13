#include <bits/stdc++.h>
#define pi acos(-1)
#define cilindro(D) (pi * (D*D*D) / 4.0)
#define tronco2(D,d) (pi * ((D*D*D)-(d*d*d))/12.0)
using namespace std;

int D, V;
double d0, df, d;
bool f;


double calc(double x) {
     double remain= cilindro(x)+tronco2(D,x) + (double)V;
     return remain;
}

int main()
{
    double x, y;
    while(cin >> D >> V && D && V) {
       x = cilindro(D);
       f=false;
       d0 = 0;
       df = x;
       while(!f) {
		   d = (d0+df)/2.0;
		   y = calc(d);
		   if(fabs(y - x) < 0.00001) f = true;
		   else if(x < y) df=d;
		   else d0=d;
	   }
	   printf("%.3lf\n", d);
    }
}

