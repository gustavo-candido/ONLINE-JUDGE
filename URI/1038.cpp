#include <stdio.h>

main ()
{
    int a,b;
    scanf("%d %d", &a, &b);
    if (a == 1) {
        printf("Total: R$ %.2f\n", 4.00 * b);
    } else if (a==2) {
        printf("Total: R$ %.2f\n", 4.50 * b);
    } else if (a==3) {
        printf("Total: R$ %.2f\n", 5.00 * b);
    } else if (a==4) {
        printf("Total: R$ %.2f\n", 2.00 * b);
    } else if (a==5) {
        printf("Total: R$ %.2f\n", 1.50 * b);
    }
}