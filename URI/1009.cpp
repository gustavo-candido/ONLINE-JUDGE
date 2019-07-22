#include <stdio.h>

int  main()
{
    char nome[50];
    double salario, montante, total;
    
    scanf("%s", nome);

    scanf("%lf %lf", &salario, &montante);
    
    total = salario + 0.15 * montante;
    
    printf("TOTAL = R$ %.2lf\n", total);
}
