#include <bits/stdc++.h>
using namespace std;

int main()
{
    double pi = 3.14, v, h, d, a;

    while(scanf("%lf %lf", &v, &d) != EOF) {
        h = (v/pi) / ((d/2.0)*(d/2.0));
        a = (pi * ((d/2.0)*(d/2.0)));

        printf("ALTURA = %.2lf\n", h);
        printf("AREA = %.2lf\n", a);
    }
}
