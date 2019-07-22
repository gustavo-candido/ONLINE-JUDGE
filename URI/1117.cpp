#include <stdio.h>
main ()
{
    float A, B;

    while (1) {
    scanf("%f", &A);
    if (A>=0 && A<=10) {
    A = A;
    break;
    }
    else {
        printf("nota invalida\n");
    }
}

    while (1) {
    scanf("%f", &B);
    if (B>=0 && B<=10) {
    B = B;
    break;
    }
    else {
        printf("nota invalida\n");
    }

}
    printf("media = %.2f\n", (A + B) / 2 );
}