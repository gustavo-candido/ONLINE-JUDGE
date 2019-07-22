#include<stdio.h>
#include<math.h>
int main(){

    double A,B,C;
    double AT,AC,ATR,AQ,AR;
    scanf("%lf %lf %lf",&A,&B,&C);
//a)
    AT=(A*C)/2.0;
    printf("TRIANGULO: %.3lf\n",AT);
//b)
    AC=3.14159*C*C;
    printf("CIRCULO: %.3lf\n",AC);
//c)
    ATR=((A+B)*C)/2.0;
    printf("TRAPEZIO: %.3lf\n",ATR);
//d)
    AQ=B*B;
    printf("QUADRADO: %.3lf\n",AQ);
//e)
    AR=A*B;
    printf("RETANGULO: %.3lf\n",AR);
}
