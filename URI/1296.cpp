#include <stdio.h>
#include <math.h>

int main()
{
    double A,B,C;
    while(scanf("%lf %lf %lf",&A,&B,&C)!=EOF){
        double P=(A+B+C)/2.0;
        double area=(4/3.0)*sqrt(P*(P-A)*(P-B)*(P-C));
        if(!(area > 0)){
            area = -1;
        }
         printf("%.3F\n",area);
        }
}
