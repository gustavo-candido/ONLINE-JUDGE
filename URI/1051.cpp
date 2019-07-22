#include <stdio.h>
main ()
{
    float a;
    scanf("%f",&a);
    if(a <= 2000)
        printf("Isento\n");
    else if (a > 2000 && a <= 3000)
        printf("R$ %.2f\n",(a-2000)*0.08);
    else if (a > 3000 && a <= 4500)
        printf("R$ %.2f\n",( ((a-3000)*0.18) + 80.00) ) ;
    else if (a > 4500)
        printf("R$ %.2f\n",( ((a-4500)*0.28) + 350.00 ));
}