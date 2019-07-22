#include <stdio.h>
main ()
{
    int i=0, H;
    float A[100];
    while (i<100) {
        scanf("%f", &A[i]);
        H = A[i];
        if (A[i]<=10 && A[i]-H!=0) {
            printf("A[%d] = %.1f\n", i, A[i]);
        }
        if (A[i]<=10 && A[i]-H==0) {
            printf("A[%d] = %.0f\n", i, A[i]);
        }
        i++;
    }
}
