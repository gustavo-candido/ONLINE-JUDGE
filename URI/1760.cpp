#include <stdio.h>
#include <math.h>
 
main ()
{
    int l;
    double A, area;
 
        while (scanf("%d", &l) != EOF) {
        A= (l*l) * sqrt(3) / 2;
        area =  (2*(sqrt(3)*l*l)/5);
        printf("%.2F\n", area);
    }
}