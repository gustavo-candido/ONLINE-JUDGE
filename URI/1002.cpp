#include <stdio.h>

int main()
{
    double raio, pi = 3.14159, area;

    scanf("%lf", &raio);

    area = raio*raio*pi;

    printf("A=%.4lf\n", area);

}
