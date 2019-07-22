#include <stdio.h>
main ()
{
        int A, B=0;
        float C=0;
    while(1) {
        scanf("%d", &A);
        if (A<0) {
            break;
        }
        else {
        C = A + C;
        B++;
        }
    }
    printf("%.2f\n", C/B);
}
