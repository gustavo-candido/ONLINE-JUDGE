#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main ()
{
    double x1, x2, y1, y2, ENF, CMD, AB, H1, H2;

    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &CMD, &ENF)!=EOF) {
        AB = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        H1 = 1/tan(CMD*PI/180);
        H2 = 1/tan(ENF*PI/180);
        printf("%.3F\n", AB *(H1+H2));
    }
}
