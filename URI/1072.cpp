#include<stdio.h>

main ()
{
   int b,N, X, IN=0, OUT=0;
   scanf("%d", &N);
   for (b=0; b<N; b++) {
        scanf("%d", &X);
        if (X>=10 && X<=20) {
            IN++;
        } else {
        OUT++;
        }
   }
   printf("%d in\n", IN);
   printf("%d out\n", OUT);
}