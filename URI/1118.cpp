#include <stdio.h>
main ()
{
    int X=1, K=1;
    float A, B;
    while (X<2) {
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
    printf("media = %.2f\n", (A + B) / 2 );
    break;
    }
    else {
        printf("nota invalida\n");
    }
}
while (K<2) {
printf("novo calculo (1-sim 2-nao)\n");
scanf("%d", &X);
if (X==2) {
    K = 100;
}
if (X==1) {
    K=1;
    X=1;
    break;
}
}
}
}